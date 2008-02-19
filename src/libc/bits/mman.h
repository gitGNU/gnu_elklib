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

#ifndef LIBC_BITS_MMAN_H
#define LIBC_BITS_MMAN_H

#include "config.h"
#include "compiler/cdefs.h"

__BEGIN_DECLS

#define PROT_READ       1
#define PROT_WRITE      2
#define PROT_EXEC       4
#define PROT_NONE       0

#define MAP_SHARED      1
#define MAP_PRIVATE     2

#define MS_ASYNC        1 /* Sync memory asynchronously.  */
#define MS_SYNC         4 /* Synchronous memory sync.  */
#define MS_INVALIDATE   2 /* Invalidate the caches.  */

__END_DECLS

#endif /* LIBC_SYS_MMAN_H */
