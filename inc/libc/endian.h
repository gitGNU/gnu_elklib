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

#ifndef ELKLIB_LIBC_ENDIAN_H
#define ELKLIB_LIBC_ENDIAN_H

#include "elklib.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

/*
 * Definitions for byte order, according to significance of bytes,
 * from low addresses to high addresses.  The value is what you get by
 * putting '4' in the most significant byte, '3' in the second most
 * significant byte, '2' in the second least significant byte, and '1'
 * in the least significant byte, and then writing down one digit for
 * each byte, starting with the byte at the lowest address at the left,
 * and proceeding to the byte with the highest address at the right.
 */

#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN    4321
#define __PDP_ENDIAN    3412

/*
 * This file defines `__BYTE_ORDER' for the particular machine we are
 * compiling for ...
 */
#include "libc/bits/endian.h"

/* Do some consistency checks ... */
#ifndef __BYTE_ORDER
#error Target machine byte-ordering is not defined ...
#endif

#if !defined(WORDS_LITTLEENDIAN) && !defined(WORDS_BIGENDIAN)
#error Compiler byte-ordering is not defined ...
#endif

#if defined(WORDS_LITTLEENDIAN) && defined(WORDS_BIGENDIAN)
#error Compiler byte-ordering wrongly defined ...
#endif

#if defined(WORDS_LITTLEENDIAN)
#if (__BYTE_ORDER != __LITTLE_ENDIAN)
#error Endianess problems (little-endian)
#endif
#endif

#if defined(WORDS_BIGENDIAN)
#if (__BYTE_ORDER != __BIG_ENDIAN)
#error Endianess prolems (big-endian)
#endif
#endif

__END_DECLS

#endif /* ELKLIB_LIBC_ENDIAN_H */
