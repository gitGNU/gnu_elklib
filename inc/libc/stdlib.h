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

#ifndef ELKLIB_LIBC_STDLIB_H
#define ELKLIB_LIBC_STDLIB_H

#include "elklib.h"
#include "libc/limits.h"
#include "libc/stdint.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

void*              bsearch(const void* key,
			   const void* base,
			   size_t      nmemb,
			   size_t      size,
			   int         (* compar)(const void*, const void *));
void               qsort(void*  base,
			 size_t nmemb,
			 size_t size,
			 int    (*compar)(const void *, const void *));

int                atoi(const char* num); 
long               atol(const char* s);
unsigned long      atoul(const char* s);
long long          atoll(const char* s);
double             atof(const char* s);

int                abs(int n);
long               labs(long n);

long               strtol(const char* cp, char** endp,unsigned int base);
long long          strtoll(const char* cp, char** endp,unsigned int base);
unsigned long      strtoul(const char* cp, char** endp,unsigned int base);
unsigned long long strtoull(const char* cp, char** endp,unsigned int base);
double             strtod(const char* s, char** scan_end);

typedef struct div_t {
	int quot;
	int rem;
} div_t;

div_t              div(int num, int denom);

typedef struct ldiv_t {
	long quot;
	long rem;
} ldiv_t;

ldiv_t             ldiv(long num, long denom);

typedef struct lldiv_t {
	long long quot;
	long long rem;
} lldiv_t;

lldiv_t            lldiv(long long num, long long denom);

void*              malloc(size_t size);
void               free(void* address);
void*              calloc(size_t nmemb, size_t size);
void*              realloc(void* ptr, size_t size);
void*              valloc(size_t size);
void*              memalign(size_t boundary, size_t size);


#define ATEXIT_MAX   32
int                atexit(void (* function)(void));

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
void               exit(int status);

#define RAND_MAX     INT_MAX
int                rand(void);
int                rand_r(unsigned int* seedp);
void               srand(unsigned int seed);

int                setenv(const char *name, const char *value, int overwrite);
int                unsetenv(const char *name);
char*              getenv(const char *name);
int                putenv(char *string);

__END_DECLS

#endif /* ELKLIB_LIBC_STDLIB_H */
