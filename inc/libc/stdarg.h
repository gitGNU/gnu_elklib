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

#ifndef ELKLIB_LIBC_STDARG_H
#define ELKLIB_LIBC_STDARG_H

#include "elklib.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

#define __GNUC_VA_LIST

typedef void* __gnuc_va_list;

#define __va_rounded_size(TYPE) \
	(((sizeof(TYPE) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#define va_start(AP, LASTARG) \
	(AP = ((__gnuc_va_list) __builtin_next_arg (LASTARG)))

void va_end (__gnuc_va_list);
#define va_end(AP) \
	((void) 0)
 
#define va_arg(AP, TYPE)						   \
	(AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size(TYPE)),  \
	   *((TYPE *) (void *) ((char *) (AP) - __va_rounded_size(TYPE))))
 
#define __va_copy(dest, src) \
	(dest) = (src)

typedef __gnuc_va_list va_list;

__END_DECLS

#endif /* ELKLIB_LIBC_STDARG_H */
