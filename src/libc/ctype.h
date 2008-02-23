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

#ifndef LIBC_CTYPE_H
#define LIBC_CTYPE_H

#include "config.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

/*
 * NOTE:
 *     This ctype does not handle EOF like the standard C library
 *     is required to
 */

int isalnum(int c);
int isalpha(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isblank(int c);
int isupper(int c);
int isxdigit(int c);
int isascii(int c);
int toascii(int c);
int tolower(int c);
int toupper(int c);

__END_DECLS

#endif /* LIBC_CTYPE_H */
