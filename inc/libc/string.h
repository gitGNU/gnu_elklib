/*
 * Copyright (C) 2008, 2009 Francesco Salvestrini
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

#ifndef ELKLIB_LIBC_STRING_H
#define ELKLIB_LIBC_STRING_H

#include "elklib.h"
#include "libc/stdint.h"
#include "libc/stdarg.h"

__BEGIN_DECLS

size_t strlen(const char* s);
size_t strnlen(const char* s, size_t count);
int    strcmp(const char* cs, const char* ct);
int    strncmp(const char* cs, const char* ct, size_t count);
char*  strcpy(char* dest, const char* src);
char*  strncpy(char* dest, const char* src, size_t count);
char*  strcat(char* dest, const char* src);
char*  strncat(char* dest, const char* src, size_t count);
char*  strchr(const char* s, int c);
char*  strrchr(const char* s, int c);
char*  strstr(const char* s1, const char* s2);
char*  strdup(const char* s);
char*  strndup(const char* s, size_t n);
int    strcasecmp(const char* s1, const char* s2);
int    strncasecmp(const char* s1, const char* s2, size_t n);
char*  strpbrk(const char* s, const char* accept);
char*  strsep(char** stringp, const char* delim);
size_t strspn(const char* s1, const char* s2);
size_t strcspn(const char* s1, const char* s2);
char*  strtok(char* s, const char* delim);
char*  strtok_r(char* s, const char* delim, char** last);

char*  index(const char* s, int c);
char*  rindex(const char* s, int c);

void*  memset(void* s, int c, size_t count);
void*  memcpy(void* dest, const void* src, size_t count);
void*  memmove(void* dest, const void* src, size_t count);
int    memcmp(const void* cs, const void* ct, size_t count);
void*  memchr(const void* s, int c, size_t count);

int    ffs(int i);
int    ffsl(long int i);
int    ffsll(long long int i);

__END_DECLS

#endif /* ELKLIB_LIBC_STRING_H */
