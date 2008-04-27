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
#include "libc/ctype.h"
#include "libc/string.h"
#include "libc/stddef.h"
#include "libc/stdlib.h"
#include "libcompiler/macro.h"

//#include "core/dbg/bug.h"
//#include "core/mem/heap.h"

char* strcat(char*       destination,
	     const char* source)
{
	char* tmp;

	tmp = destination;

	while (*destination) {
		destination++;
	}
	/* destination--; */
	while ((*destination++ = *source++) != '\0') {
		/* nothing */
	}

	return tmp;
}

char* strchr(const char* s,
	     int         c)
{
	char* cursor;

	cursor = (char *) s;
	while (1) {
		if (*cursor == c) {
			return cursor;
		}
		if (*cursor == '\0') {
			return NULL;
		}

		cursor++;
	}
}

char* index(const char* s,
	    int         c)
{
	return strchr(s, c);
}

char* strrchr(const char* s,
	      int         c)
{
	char* save;

	for (save = NULL; *s != 0; s++) {
		if (*s == c) {
			save = (char *)s;
		}
	}

	return save;
}

char* rindex(const char* s,
	     int         c)
{
	return strrchr(s, c);
}

int strcmp(const char* source,
	   const char* target)
{
	register signed char res;

	while (1) {
		if ((res = *source - *target++) != 0 || !*source++) {
			break;
		}
	}

	return res;
}

int strncmp(const char*  source,
	    const char*  target,
	    unsigned int count)
{
	register signed char res;

	res = 0;
	while (count) {
		if ((res = *source - *target++) != 0 || !*source++) {
			break;
		}
		count--;
	}

	return res;
}

char* strcpy(char*       destination,
	     const char* source)
{
	char* tmp;

	tmp = destination;
	while ((*destination++ = *source++) != '\0') {
		/* nothing */
	}

	return (tmp);
}

char* strncpy(char*        destination,
	      const char*  source,
	      unsigned int count)
{
	char* tmp;

	tmp = destination;
	while (count-- && (*destination++ = *source++) != '\0') {
		/* nothing */
	}

	return (tmp);
}

size_t strlen(const char* string)
{
	const char* p;

	for (p = string; *p != '\0'; ++p) {
		/* Nothing to do */
	}

	return (p - string);
}

size_t strnlen(const char*  string,
	       unsigned int count)
{
	const char* sc;

	for (sc = string; count-- && *sc != '\0'; ++sc) {
		/* nothing */
	}

	return (sc - string);
}

char* strncat(char*        destination,
	      const char*  source,
	      unsigned int count)
{
	char* tmp;

	tmp = destination;
	if (count) {
		while (*destination) {
			destination++;
		}
		while ((*destination++ = *source++)) {
			if (--count == 0) {
				*destination = '\0';
				break;
			}
		}
	}

	return tmp;
}

char* strstr(const char* s1,
	     const char* s2)
{
	int l1, l2;

	l2 = strlen (s2);
	if (!l2) {
		return (char *) s1;
	}
	l1 = strlen (s1);
	while (l1 >= l2) {
		l1--;
		if (!memcmp (s1, s2, l2)) {
			return (char *) s1;
		}
		s1++;
	}

	return NULL;
}

char* strdup(const char* s)
{
	char* buf;

	buf = (char *) malloc(strlen(s) + 1);
	if (buf != NULL) {
		strcpy(buf, s);
	}

	return buf;
}

char* strndup(const char* s, size_t n)
{
	char*  buf;
	size_t l;

	l   = strnlen(s, n); /* Avoid problem if s is not terminated */
	buf = (char *) malloc(l + 1);
	if (buf != NULL) {
		strncpy(buf, s, l);
		buf[l] = 0;
	}

	return buf;
}

void* memchr(const void*  s,
	     int          c,
	     unsigned int n)
{
	const unsigned char* p;

	p = (unsigned char *) s;
	while (n-- != 0) {
		if (((char) c) == *p) {
			return ((void *) p);
		}
		p++;
	}

	return NULL;
}

void* memcpy(void*        destination,
	     const void*  source,
	     unsigned int count)
{
	char* tmp;
	char* s;

	tmp = (char *) destination;
	s   = (char *) source;

	while (count--) {
		*tmp++ = *s++;
	}

	return destination;
}

int memcmp(const void*  source,
	   const void*  destination,
	   unsigned int count)
{
	const unsigned char* su1;
	const unsigned char* su2;
	int                  result = 0;

	for (su1 = (unsigned char *)source, su2 = (unsigned char* )destination;
	     0 < count;
	     ++su1, ++su2, count--) {

		result = *su1 - *su2;

		if (result != 0) {
			break;
		}
	}

	return result;
}

void* memset(void*        s,
	     int          c,
	     unsigned int count)
{
	char* xs = (char *) s;

	while (count--) {
		*xs++ = c;
	}

	return s;
}

void* memmove(void*        destination,
	      const void*  source,
	      unsigned int count)
{
	char* tmp;
	char* s;

	if (destination <= source) {
		tmp = (char *) destination;
		s   = (char *) source;

		while (count--) {
			*tmp++ = *s++;
		}
	} else {
		tmp = (char *) destination + count;
		s   = (char *) source + count;
		while (count--)
			*--tmp = *--s;
	}

	return destination;
}

char* strtok(char*       s,
	     const char* delim)
{
	char*        spanp;
	int          c, sc;
	char*        tok;
	static char* last;


	if (s == NULL && (s = last) == NULL) {
		return NULL;
	}

	/*
	 * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
	 */
 cont:
	/* Please remove the 'cont:' label ASAP ... */
	c = *s++;
	for (spanp = (char *) delim; (sc = *spanp++) != 0;) {
		if (c == sc) {
			goto cont;
		}
	}

	if (c == 0) {		/* no non-delimiter characters */
		last = NULL;
		return NULL;
	}
	tok = s - 1;

	/*
	 * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
	 * Note that delim must have one NUL; we stop if we see that, too.
	 */
	for (;;) {
		c = *s++;
		spanp = (char *) delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0) {
					s = NULL;
				} else {
					s[-1] = 0;
				}
				last = s;
				return tok;
			}
		} while (sc != 0);
	}

	/* This point shouldn't be reached */
	bug();
}

char* strtok_r(char*       s,
	       const char* delim,
	       char**      last)
{
	char* spanp;
	int   c, sc;
	char* tok;

	if (s == NULL && (s = *last) == NULL) {
		return NULL;
	}

	/*
	 * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
	 */
 cont:
	/* Please remove the 'cont:' label ASAP ... */
	c = *s++;
	for (spanp = (char *) delim; (sc = *spanp++) != 0;) {
		if (c == sc) {
			goto cont;
		}
	}

	if (c == 0) {		/* no non-delimiter characters */
		*last = NULL;
		return NULL;
	}
	tok = s - 1;

	/*
	 * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
	 * Note that delim must have one NUL; we stop if we see that, too.
	 */
	for (;;) {
		c = *s++;
		spanp = (char *) delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0) {
					s = NULL;
				} else {
					s[-1] = 0;
				}
				*last = s;
				return tok;
			}
		} while (sc != 0);
	}

	/* This point shouldn't be reached */
	bug();
}

size_t strspn(const char* s1, const char* s2)
{
	const char* p;
	const char* spanp;
	char        c, sc;

	p = s1;

	/*
	 * Skip any characters in s2, excluding the terminating \0.
	 */
 cont:
	/* Please remove the 'cont:' label ASAP ... */
	c = *p++;
	for (spanp = s2; (sc = *spanp++) != 0;) {
		if (sc == c) {
			goto cont;
		}
	}

	return (p - 1 - s1);
}

size_t strcspn(const char* s1,
	       const char* s2)
{
	const char* p;
	const char* spanp;
	char        c, sc;

	/*
	 * Stop as soon as we find any character from s2.  Note that there
	 * must be a NUL in s2; it suffices to stop when we find that, too.
	 */
	for (p = s1;;) {
		c = *p++;
		spanp = s2;
		do {
			if ((sc = *spanp++) == c) {
				return (p - 1 - s1);
			}
		} while (sc != 0);
	}

	/* This point shouldn't be reached */
	bug();
}

int strcasecmp(const char* s1, const char* s2)
{
	int r;

	r = 0;
	while (((s1 == s2) ||
		!(r = ((int)
		       (tolower(*((char *) s1))))
		  - tolower(*((char *) s2))))
	       && (++s2, *s1++));

	return r;
}

int strncasecmp(const char* s1, const char* s2, size_t n)
{
	int r;

	r = 0;
	while (n &&
	       ((s1 == s2) ||
		!(r = ((int)
		       (tolower(*((char *) s1))))
		  - tolower(*((char *) s2)))) &&
	       (--n, ++s2, *s1++));

	return r;
}

char* strpbrk(const char* s, const char* accept)
{
	const char* t;
	const char* p;

	for (t = s; *t; t++) {
		for (p = accept; *p; p++) {
			if (*p == *t) {
				return (char *) t; /* silence the warning */
			}
		}
	}

	return NULL;
}

char* strsep(char** stringp, const char* delim)
{
	char* begin;
	char* end;

	begin = *stringp;

	if (begin == NULL) {
		return NULL;
	}

	if (delim[0] == '\0' || delim[1] == '\0') {
		char ch;

		/* One character delimiter */
		ch = delim[0];
		if (ch == '\0') {
			end = NULL;
		} else {
			if (*begin == ch) {
				end = begin;
			} else if (*begin == '\0') {
				end = NULL;
			} else {
				end = strchr(begin + 1, ch);
			}
		}
	} else {
		/* Find the end of the token.  */
		end = strpbrk(begin, delim);
	}

	if (end) {
		/* Terminate the token and set *STRINGP past NUL character.  */
		*end++   = '\0';
		*stringp = end;
	} else {
		/* No more delimiters; this is the last token.  */
		*stringp = NULL;
	}

	return begin;
}

int ffsll(long long int i)
{
	long long int n;

	/* Linear search, slow but small */
	for (n = 0 ; i ; ++n) {
		i >>= 1;
	}

	return n;
}

int ffsl(long int i)
{
	return ffsll(i);
}

int ffs(int i)
{
	return ffsll(i);
}
