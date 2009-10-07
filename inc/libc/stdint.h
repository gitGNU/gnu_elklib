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

#ifndef ELKLIB_LIBC_STDINT_H
#define ELKLIB_LIBC_STDINT_H

#include "elklib.h"
#include "libc/bits/wordsize.h"

typedef int                int_t;
typedef unsigned int       uint_t;
typedef char               int8_t;
typedef unsigned char      uint8_t;
typedef short int          int16_t;
typedef unsigned short     uint16_t;
typedef int                int32_t;
typedef unsigned int       uint32_t;

#if __WORDSIZE == 64
typedef long int           int64_t;
typedef unsigned long int  uint64_t;
#else
typedef long long          int64_t;
typedef unsigned long long uint64_t;
#endif

typedef uint_t             size_t;
typedef int_t              ssize_t;

#define SIZE_MAX           ((size_t) -1)

#endif /* ELKLIB_LIBC_STDINT_H */
