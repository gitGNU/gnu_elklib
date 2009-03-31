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

#ifndef ELKLIB_LIBC_BITS_VALUES_H
#define ELKLIB_LIBC_BITS_VALUES_H

#include "elklib.h"

__BEGIN_DECLS

#define _TYPEBITS(type) (sizeof (type) * CHAR_BIT)

#define CHARBITS        _TYPEBITS(char)
#define SHORTBITS       _TYPEBITS(short int)
#define INTBITS         _TYPEBITS(int)
#define LONGBITS        _TYPEBITS(long int)
#define PTRBITS         _TYPEBITS(char *)
#define DOUBLEBITS      _TYPEBITS(double)
#define FLOATBITS       _TYPEBITS(float)

#define MINSHORT        SHRT_MIN
#define MININT          INT_MIN
#define MINLONG         LONG_MIN

#define MAXSHORT        SHRT_MAX
#define MAXINT          INT_MAX
#define MAXLONG         LONG_MAX

#define HIBITS          MINSHORT
#define HIBITL          MINLONG

__END_DECLS

#endif /* ELKLIB_LIBC_BITS_VALUES_H */
