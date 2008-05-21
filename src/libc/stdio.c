/*
 * Copyright (C) 2007, 2008 Francesco Salvestrini
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "config.h"
#include "debug.h"
#include "libc/limits.h"
#include "libc/ctype.h"
#include "libc/stdio.h"
#include "libc/string.h"
#include "libc/stdlib.h"
#include "libc/stdarg.h"
#include "libc/stddef.h"
#include "libcompiler/macro.h"
#include "libcompiler/compiler.h"

static FILE _stdin  = FILE_INITIALIZER;
FILE*       stdin   = &_stdin;

static FILE _stdout = FILE_INITIALIZER;
FILE*       stdout  = &_stdout;

static FILE _stderr = FILE_INITIALIZER;
FILE*       stderr  = &_stderr;


void FILE_set(FILE* stream,
	      int   (*putchar_func)(int character),
	      int   (*getchar_func)(void),
	      int   (*fseek_func)(long offset, int whence),
	      long  (*ftell_func)(void))
{
	assert(stream);

	/*
	 * NOTE:
	 *     Fill in the provided call-back even if they are NULL. You can
	 *     pass NULL to this function in order to stop the use of a
	 *     particular call-back.
	 */
	stream->putchar = putchar_func;
	stream->getchar = getchar_func;
	stream->fseek   = fseek_func;
	stream->ftell   = ftell_func;
}

void FILE_get(FILE* stream,
	      int   (**putchar_func)(int character),
	      int   (**getchar_func)(void),
	      int   (**fseek_func)(long offset, int whence),
	      long  (**ftell_func)(void))
{
	assert(stream);

	/*
	 * NOTE:
	 *     Retrieve the provided call-back only for those who have a
	 *     non-NULL associated variable.
	 */
	if (putchar_func) {
		*putchar_func = stream->putchar;
	}
	if (getchar_func) {
		*getchar_func = stream->getchar;
	}
	if (fseek_func) {
		*fseek_func   = stream->fseek;
	}
	if (ftell_func) {
		*ftell_func   = stream->ftell;
	}
}

void FILE_update(FILE* stream,
		 int   (*putchar_func)(int character),
		 int   (*getchar_func)(void),
		 int   (*fseek_func)(long offset, int whence),
		 long  (*ftell_func)(void))
{
	assert(stream);

	/*
	 * NOTE:
	 *     Fill in the provided call-back. You can pass NULL to this
	 *     function in order to stop the use of a particular call-back.
	 */
	if (putchar_func) {
		stream->putchar = putchar_func;
	}
	if (getchar_func) {
		stream->getchar = getchar_func;
	}
	if (fseek_func) {
		stream->fseek   = fseek_func;
	}
	if (ftell_func) {
		stream->ftell   = ftell_func;
	}
}

int fgetc(FILE* stream)
{
	assert(stream);

	if (stream->getchar) {
		return stream->getchar();
	}

	/* Sorry, this stream is not readable ... */
	return EOF;
}

int getchar(void)
{
	return fgetc(stdin);
}

int getc(FILE *stream)
{
	assert(stream);

	return fgetc(stream);
}

int printf(const char* format, ...)
{
	va_list args;
	int     i;

	va_start(args, format);
	i = vfprintf(stdout, format, args);
	va_end(args);

	return i;
}

int sscanf(const char* buf, const char* format, ...)
{
	va_list args;
	int     i;

	va_start(args, format);
	i = vsscanf(buf, format, args);
	va_end(args);

	return i;
}

int sprintf(char* buf, const char* format, ...)
{
	va_list args;
	int     i;

	va_start(args, format);
	i = vsprintf(buf, format, args);
	va_end(args);

	return i;
}

int snprintf(char* buf, size_t size, const char* format, ...)
{
	va_list args;
	int     i;

	va_start(args, format);
	i = vsnprintf(buf, size, format, args);
	va_end(args);

	return i;
}

static int skip_atoi(const char **s)
{
	int i=0;

	while (isdigit(**s)) {
		i = i * 10 + *((*s)++) - '0';
	}

	return i;
}

static unsigned long long do_div(unsigned long long* n,
				 unsigned            base)
{
	unsigned long long res;

	assert(base != 0);

	res = (*n) % (unsigned long long) base;
	*n  = (*n) / (unsigned long long) base;

	return res;
}

#define ZEROPAD	1		/* pad with zero */
#define SIGN	2		/* unsigned/signed long */
#define PLUS	4		/* show plus */
#define SPACE	8		/* space if plus */
#define LEFT	16		/* left justified */
#define SPECIAL	32		/* 0x */
#define LARGE	64		/* use 'ABCDEF' instead of 'abcdef' */

static char* number(char*     buf,
		    char*     end,
		    long long num,
		    int       base,
		    int       size,
		    int       precision,
		    int       type)
{
	char c, sign, tmp[66];
	const char* digits;
	static const char small_digits[] =
		"0123456789abcdefghijklmnopqrstuvwxyz";
	static const char large_digits[] =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;

	digits = (type & LARGE) ? large_digits : small_digits;
	if (type & LEFT) {
		type &= ~ZEROPAD;
	}
	if (base < 2 || base > 36) {
		return 0;
	}
	c = (type & ZEROPAD) ? '0' : ' ';

	sign = 0;
	if (type & SIGN) {
		if (num < 0) {
			sign = '-';
			num = -num;
			size--;
		} else if (type & PLUS) {
			sign = '+';
			size--;
		} else if (type & SPACE) {
			sign = ' ';
			size--;
		}
	}
	if (type & SPECIAL) {
		if (base == 16) {
			size -= 2;
		} else {
			if (base == 8) {
				size--;
			}
		}
	}
	i = 0;
	if (num == 0) {
		tmp[i++]='0';
	} else {
		while (num != 0) {
			assert(num >= 0);  /* Check for wrong signedness */
			assert(base > 0);  /* Check for wrong signedness */

			/* The cast is needed to stop the compiler barf */
			tmp[i++] =
				digits[do_div((unsigned long long *) &num,
					      base)];
		}
	}
	if (i > precision) {
		precision = i;
	}
	size -= precision;
	if (!(type & (ZEROPAD+LEFT))) {
		while (size-- > 0) {
			if (buf <= end) {
				*buf = ' ';
			}
			++buf;
		}
	}
	if (sign) {
		if (buf <= end) {
			*buf = sign;
		}
		++buf;
	}
	if (type & SPECIAL) {
		if (base == 8) {
			if (buf <= end) {
				*buf = '0';
			}
			++buf;
		} else if (base==16) {
			if (buf <= end) {
				*buf = '0';
			}
			++buf;
			if (buf <= end) {
				*buf = digits[33];
			}
			++buf;
		}
	}
	if (!(type & LEFT)) {
		while (size-- > 0) {
			if (buf <= end) {
				*buf = c;
			}
			++buf;
		}
	}
	while (i < precision--) {
		if (buf <= end) {
			*buf = '0';
		}
		++buf;
	}
	while (i-- > 0) {
		if (buf <= end) {
			*buf = tmp[i];
		}
		++buf;
	}
	while (size-- > 0) {
		if (buf <= end) {
			*buf = ' ';
		}
		++buf;
	}
	return buf;
}

int vsnprintf(char* buf, size_t size, const char* format, va_list args)
{
	int                len;
	unsigned long long num;
	int                i, base;
	char*              str;
	char*              end;
	char               c;
	const char*        s;

	int                flags;
	int                field_width;
	int                precision;
	int                qualifier;

	assert(buf);
	assert(size > 0);
	assert(format);

	str = buf;
	end = buf + size - 1;

	if (end < buf - 1) {
		end = (char *)((void *) -1);
		size = end - buf + 1;
	}

	for (; *format ; ++format) {
		if (*format != '%') {
			if (str <= end) {
				*str = *format;
			}
			++str;
			continue;
		}

		/* process flags */
		flags = 0;
	repeat:
		++format;		/* this also skips first '%' */
		switch (*format) {
			case '-': flags |= LEFT;    goto repeat;
			case '+': flags |= PLUS;    goto repeat;
			case ' ': flags |= SPACE;   goto repeat;
			case '#': flags |= SPECIAL; goto repeat;
			case '0': flags |= ZEROPAD; goto repeat;
			default:                                 break;
		}

		/* get field width */
		field_width = -1;
		if (isdigit(*format)) {
			field_width = skip_atoi(&format);
		} else if (*format == '*') {
			++format;
			/* it's the next argument */
			field_width = va_arg(args, int);
			if (field_width < 0) {
				field_width = -field_width;
				flags |= LEFT;
			}
		}

		/* get the precision */
		precision = -1;
		if (*format == '.') {
			++format;
			if (isdigit(*format)) {
				precision = skip_atoi(&format);
			} else if (*format == '*') {
				++format;
				/* it's the next argument */
				precision = va_arg(args, int);
			}

			if (precision < 0) {
				precision = 0;
			}
		}

		/* get the conversion qualifier */
		qualifier = -1;
		if (*format == 'h' ||
		    *format == 'l' || *format == 'L' ||
		    *format == 'Z' || *format == 'z') {
			qualifier = *format;
			++format;
			if (qualifier == 'l' && *format == 'l') {
				qualifier = 'L';
				++format;
			}
		}

		/* default base */
		base = 10;

		switch (*format) {
		case 'c':
			if (!(flags & LEFT)) {
				while (--field_width > 0) {
					if (str <= end) {
						*str = ' ';
					}
					++str;
				}
			}
			c = (unsigned char) va_arg(args, int);
			if (str <= end) {
				*str = c;
			}
			++str;
			while (--field_width > 0) {
				if (str <= end) {
					*str = ' ';
				}
				++str;
			}
			continue;

		case 's':
			s = va_arg(args, char *);

#if 0
			if ((unsigned long)s < PAGE_SIZE) {
				s = "<NULL>";
			}
#endif

			len = strnlen(s, precision);

			if (!(flags & LEFT)) {
				while (len < field_width--) {
					if (str <= end) {
						*str = ' ';
					}
					++str;
				}
			}
			for (i = 0; i < len; ++i) {
				if (str <= end) {
					*str = *s;
				}
				++str;
				++s;
			}
			while (len < field_width--) {
				if (str <= end) {
					*str = ' ';
				}
				++str;
			}
			continue;

		case 'p':
			if (field_width == -1) {
				field_width = 2 * sizeof(void *);
				flags |= ZEROPAD;
			}
			str = number(str, end,
				     (unsigned long) va_arg(args, void *),
				     16, field_width,
				     precision, flags);
			continue;


		case 'n':
			/* XXX FIXME:
			 *     What does C99 say about the overflow
			 *     case here?
			 */
			if (qualifier == 'l') {
				long* ip;

				ip  = va_arg(args, long *);
				*ip = (str - buf);
			} else if ((qualifier == 'Z') ||
				   (qualifier == 'z')) {
				size_t* ip;

				ip  = va_arg(args, size_t *);
				*ip = (str - buf);
			} else {
				int* ip;

				ip  = va_arg(args, int *);
				*ip = (str - buf);
			}
			continue;

		case '%':
			if (str <= end) {
				*str = '%';
			}
			++str;
			continue;

			/* integer number formats, set up the flags
			 * and "break" ...
			 */
		case 'o':
			base = 8;
			break;

		case 'X':
			flags |= LARGE;
		case 'x':
			base = 16;
			break;

		case 'd':
		case 'i':
			flags |= SIGN;
		case 'u':
			break;

		default:
			if (str <= end)
				*str = '%';
			++str;
			if (*format) {
				if (str <= end) {
					*str = *format;
				}
				++str;
			} else {
				--format;
			}
			continue;
		}

		if (qualifier == 'L') {
			num = va_arg(args, long long);
		} else if (qualifier == 'l') {
			num = va_arg(args, unsigned long);
			if (flags & SIGN) {
				num = (signed long) num;
			}
		} else if (qualifier == 'Z' || qualifier == 'z') {
			num = va_arg(args, size_t);
		} else if (qualifier == 'h') {
			num = (unsigned short) va_arg(args, int);
			if (flags & SIGN) {
				num = (signed short) num;
			}
		} else {
			num = va_arg(args, unsigned int);
			if (flags & SIGN) {
				num = (signed int) num;
			}
		}
		str = number(str, end, num, base,
			     field_width, precision, flags);
	}

	if (str <= end) {
		*str = '\0';
	} else if (size > 0) {
		/* don't write out a null byte if the buf size is zero */
		*end = '\0';
	}

	/*
	 * the trailing null byte doesn't count towards the total
	 * ++str;
	 */

	return (str - buf);
}

int vsprintf(char* buf, const char* format, va_list args)
{
	return vsnprintf(buf, (~0U) >> 1, format, args);
}

int vsscanf(const char* buf, const char* format, va_list args)
{
	const char* str          = buf;
	char*       next;
	char        digit;
	int         num          = 0;
	int         qualifier;
	int         base;
	int         field_width;
	int         is_sign      = 0;

	while (*format && *str) {
		/* skip any white space in format */
		/* white space in format matchs any amount of
		 * white space, including none, in the input.
		 */
		if (isspace(*format)) {
			while (isspace(*format)) {
				++format;
			}
			while (isspace(*str)) {
				++str;
			}
		}

		/* anything that is not a conversion must match exactly */
		if (*format != '%' && *format) {
			if (*format++ != *str++) {
				break;
			}
			continue;
		}

		if (!*format) {
			break;
		}
		++format;

		/* skip this conversion, advance both strings to next white
		 * space
		 */
		if (*format == '*') {
			while (!isspace(*format) && *format) {
				format++;
			}
			while (!isspace(*str) && *str) {
				str++;
			}
			continue;
		}

		/* get field width */
		field_width = -1;
		if (isdigit(*format)) {
			field_width = skip_atoi(&format);
		}

		/* get conversion qualifier */
		qualifier = -1;
		if (*format == 'h' ||
		    *format == 'l' || *format == 'L' ||
		    *format == 'Z' || *format == 'z') {
			qualifier = *format;
			format++;
		}

		base = 10;
		is_sign = 0;

		if (!*format || !*str) {
			break;
		}

		switch(*format++) {
		case 'c': {
			char* s = (char *) va_arg(args, char *);
			if (field_width == -1) {
				field_width = 1;
			}
			do {
				*s++ = *str++;
			} while (field_width-- > 0 && *str);
			num++;
		}
			continue;
		case 's': {
			char* s = (char *) va_arg(args, char *);

			if (field_width == -1) {
				field_width = INT_MAX;
			}

			/*
			 * first, skip leading white space
			 * in buffer
			 */
			while (isspace(*str)) {
				str++;
			}

			/* now copy until next white space */
			while (*str &&
			       !isspace(*str)
			       && field_width--) {
				*s++ = *str++;
			}
			*s = '\0';
			num++;
		}
			continue;
		case 'n': {
			/* return number of characters read so far */
			int* i;

			i  = (int *) va_arg(args, int*);
			*i = str - buf;
		}
			continue;
		case 'o':
			base = 8;
			break;
		case 'x':
		case 'X':
			base = 16;
			break;
		case 'i':
			base = 0;
		case 'd':
			is_sign = 1;
		case 'u':
			break;
		case '%':
			/* looking for '%' in str */
			if (*str++ != '%') {
				return num;
			}

			continue;
		default:
			/* invalid format; stop here */
			return num;
		}

		/* have some sort of integer conversion.
		 * first, skip white space in buffer.
		 */
		while (isspace(*str)) {
			str++;
		}

		digit = *str;
		if (is_sign && digit == '-') {
			digit = *(str + 1);
		}

		if (!digit
		    || (base == 16 && !isxdigit(digit))
		    || (base == 10 && !isdigit(digit))
		    || (base == 8 && (!isdigit(digit) || digit > '7'))
		    || (base == 0 && !isdigit(digit))) {
			break;
		}

		switch(qualifier) {
		case 'h':
			if (is_sign) {
				short* s;

				s  = (short *) va_arg(args, short *);
				*s = (short) strtol(str,&next,base);
			} else {
				unsigned short* s;

				s = (unsigned short *)
					va_arg(args, unsigned short *);
				*s = (unsigned short)
					strtoul(str, &next, base);
			}
			break;
		case 'l':
			if (is_sign) {
				long* l;

				l  = (long *) va_arg(args, long *);
				*l = strtol(str,&next,base);
			} else {
				unsigned long* l;

				l  = (unsigned long*)
					va_arg(args, unsigned long*);
				*l = strtoul(str,&next,base);
			}
			break;
		case 'L':
			if (is_sign) {
				long long* l;

				l  = (long long*) va_arg(args, long long *);
				*l = strtoll(str,&next,base);
			} else {
				unsigned long long* l;

				l  = (unsigned long long*)
					va_arg(args, unsigned long long*);
				*l = strtoull(str,&next,base);
			}

			break;
		case 'Z':
		case 'z': {
			size_t* s;

			s  = (size_t*) va_arg(args, size_t*);
			*s = (size_t) strtoul(str,&next,base);
		}
			break;
		default:
			if (is_sign) {
				int *i;

				i  = (int *) va_arg(args, int*);
				*i = (int) strtol(str,&next,base);
			} else {
				unsigned int* i;

				i  = (unsigned int*)
					va_arg(args, unsigned int*);
				*i = (unsigned int)
					strtoul(str,&next,base);
			}
			break;
		}
		num++;

		if (!next) {
			break;
		}

		str = next;
	}

	return num;
}

int vfprintf(FILE* stream, const char* format, va_list ap)
{
	static char  buffer[ELKLIB_PRINTF_BUFFER_LENGTH];
	unsigned int count;
	int          retval;

	assert(stream);
	assert(format);

	count = vsnprintf(buffer, sizeof(buffer), format, ap);

	retval = -1;
	if (count > 0) {
		if (stream->putchar) {
			int i;

			for (i = 0; buffer[i] != 0; i++) {
				stream->putchar(buffer[i]);
			}

			retval = count;
		}
	}

	return retval;
}

int fprintf(FILE* stream, const char* format, ...)
{
	assert(stream);

	va_list args;
	int     i;

	va_start(args, format);
	i = vfprintf(stream, format, args);
	va_end(args);

	return i;
}

int fputs(const char* s, FILE* stream)
{
	assert(s);
	assert(stream);

	if (stream->putchar) {
		int i;

		for (i = 0; s[i] != 0; i++) {
			stream->putchar(s[i]);
		}

		stream->putchar('\n');

		return 0;
	}

	return EOF;
}

int puts(const char* s)
{
	assert(s);

	return fputs(s, stdout);
}

int fputc(int c, FILE* stream)
{
	assert(stream);

	if (stream->putchar) {
		if (stream->putchar((unsigned char) c)) {
			return (unsigned char) c;
		}
	}

	return EOF;
}

int putchar(int c)
{
	return fputc(c, stdout);
}

void clearerr(FILE* stream)
{
	assert(stream);

	stream->error = 0;
	stream->eof   = 0;
}

int feof(FILE* stream)
{
	assert(stream);

	return (stream->eof ? 1 : 0);
}

int ferror(FILE* stream)
{
	assert(stream);

	return (stream->error ? 1 : 0);
}

int fflush(FILE* stream)
{
	assert(stream);

	unused_argument(stream);

	/* return 0; */
	return EOF;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE* stream)
{
	size_t done;
	size_t count;
	size_t i;

	assert(ptr);
	assert(size != 0);
	assert(nmemb != 0);
	assert(stream);

	/* XXX FIXME: This code is really crappy, please remove ASAP */

	done  = 0;
	count = size * nmemb;

	for (i = 0; i < count; i++) {
		int c;

		c = fgetc(stream);
		if (c == EOF) {
			break;
		}

		*((unsigned char *) ptr + i) = (unsigned char) c;

		done++;
	}

	return done;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE* stream)
{
	size_t done;
	size_t count;
	size_t i;

	assert(ptr);
	assert(size != 0);
	assert(nmemb != 0);
	assert(stream);

	/* XXX FIXME: This code is really crappy, please remove ASAP */

	done  = 0;
	count = size * nmemb;

	for (i = 0; i < count; i++) {
		int c;

		c = (unsigned char) (*((unsigned char *) ptr + i));
		if (fputc(c, stream) == EOF) {
			break;
		}
		done++;
	}

	return done;
}

int fseek(FILE* stream, long offset, int whence)
{
	assert(stream);
	assert((whence == SEEK_SET) ||
	       (whence == SEEK_CUR) ||
	       (whence == SEEK_END));

	if (stream->fseek) {
		/* Stream is seek-able */
		return stream->fseek(offset, whence);
	}

	/* Sorry, stream is not seek-able */
	return EOF;
}

long ftell(FILE* stream)
{
	assert(stream);

	if (stream->ftell) {
		return stream->ftell();
	}

	return EOF;
}

void rewind(FILE* stream)
{
	assert(stream);

	(void) fseek(stream, 0L, SEEK_SET);
}

int fgetpos(FILE* stream, fpos_t *pos)
{
	assert(stream);
	assert(pos);

	*pos = ftell(stream);

	return (*pos >= 0) ? 0 : EOF;
}

int fsetpos(FILE* stream, fpos_t *pos)
{
	assert(stream);
	assert(pos);

	return fseek(stream, *pos, SEEK_SET);
}
