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

#ifndef ELKLIB_LIBC_MALLOC_H
#define ELKLIB_LIBC_MALLOC_H

#include "elklib.h"
#include "libc/stddef.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

extern void* (*__malloc_hook)(size_t size, const void* caller);
extern void* (*__realloc_hook)(void* ptr, size_t size, const void* caller);
extern void* (*__memalign_hook)(size_t      alignment,
				size_t      size,
				const void* caller);
extern void  (*__free_hook)(void* ptr, const void* caller);
extern void  (*__malloc_initialize_hook)(void);
extern void  (*__after_morecore_hook)(void);

__END_DECLS

#endif /* ELKLIB_LIBC_MALLOC_H */
