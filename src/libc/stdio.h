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

#ifndef LIBC_STDIO_H
#define LIBC_STDIO_H

#include "config.h"
#include "libc/stdarg.h"
#include "libc/stdint.h"
#include "libc/bits/fcntl.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

typedef struct {
	int  error;
	int  eof;
	int  (*putchar)(int character);
	int  (*getchar)(void);
	int  (*fseek)(long offset, int whence);
	long (*ftell)(void);
} FILE;

#define FILE_INITIALIZER { 0, 0, NULL, NULL, NULL, NULL }

/*
 * NOTE:
 *     You can pass NULL to this function in order to stop the use of a
 *     particular call-back. Keep attention about what you are doing ...
 *
 */
void   FILE_set(FILE* stream,
		int   (*putchar)(int character),
		int   (*getchar)(void),
		int   (*fseek)(long offset, int whence),
		long  (*ftell)(void));

/*
 * NOTE:
 *     You can pass NULL to this function in order to not retrieve the
 *     corresponding function. Keep attention about what you are doing ...
 *
 */
void   FILE_get(FILE* stream,
		int   (**putchar)(int character),
		int   (**getchar)(void),
		int   (**fseek)(long offset, int whence),
		long  (**ftell)(void));

/*
 * NOTE:
 *     You can pass NULL to this function in order to leave unchanged a
 *     specific function. Keep attention about what you are doing ...
 *
 */
void   FILE_update(FILE* stream,
		   int   (*putchar)(int character),
		   int   (*getchar)(void),
		   int   (*fseek)(long offset, int whence),
		   long  (*ftell)(void));

extern FILE* stdout;
extern FILE* stdin;
extern FILE* stderr;

/*
 * NOTE:
 *     The following functions should mimic as much as possible those in stdio
 */
int    sscanf(const char* buf, const char* format, ...);

int    printf(const char* format, ...);
int    fprintf(FILE* stream, const char* format, ...);
int    sprintf(char* buf, const char* format, ...);
int    snprintf(char* buf, size_t size, const char* format, ...);

int    vsscanf(const char* buf, const char* format, va_list args);

int    vprintf(const char* format, va_list ap);
int    vfprintf(FILE* stream, const char* format, va_list ap);
int    vsprintf(char* buf, const char* format, va_list args);
int    vsnprintf(char* buf, size_t size, const char* format, va_list args);

#define EOF -1

int    puts(const char* string);
int    fputs(const char* s, FILE* stream);

int    fputc(int c, FILE* stream);
int    fgetc(FILE* stream);

int    putchar(int character);
int    getchar(void);
int    getc(FILE *stream);

void   clearerr(FILE* stream);
int    feof(FILE* stream);
int    ferror(FILE* stream);
int    fflush(FILE* stream);

size_t fread(void *ptr, size_t size, size_t nmemb, FILE* stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE* stream);

typedef long fpos_t;

int    fseek(FILE* stream, long offset, int whence);
long   ftell(FILE* stream);
void   rewind(FILE* stream);
int    fgetpos(FILE* stream, fpos_t *pos);
int    fsetpos(FILE* stream, fpos_t *pos);

__END_DECLS

#endif /* LIBC_STDIO_H */
