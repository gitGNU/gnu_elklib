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

#ifndef LIBC_STDDEF_H
#define LIBC_STDDEF_H

#include "config.h"
#include "libc/stdint.h"

/*
 * NOTE:
 *     GCC defines NULL and size_t inside <gcc-install-dir>/include/stddef.h
 *     We defines NULL here and size_t inside arch/types.h (because it is arch
 *     dependent)
 */

#ifndef __cplusplus
#define NULL ((void *) 0)
#else
#define NULL 0
#endif

typedef long int     ptrdiff_t; /* XXX FIXME: This typedef needs an update */
typedef int          intptr_t;  /* XXX FIXME: Find a proper place ... */
typedef unsigned int uintptr_t; /* XXX FIXME: Find a proper place ... */
typedef size_t	     uoff_t;    /* XXX FIXME: Find a proper place ... */

#endif /* LIBC_STDDEF_H */
