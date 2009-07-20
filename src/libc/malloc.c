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

#include "config.h"
#include "libc/stddef.h"
#include "libc/malloc.h"

#if 0
__malloc_hook            = NULL;
__realloc_hook           = NULL;
__memalign_hook          = NULL;
__free_hook              = NULL;
__malloc_initialize_hook = NULL;
__after_morecore_hook    = NULL;
#endif

struct mallinfo mallinfo(void)
{
        struct mallinfo temp;

        /* XXX FIXME: fill temp appropriately ... */

        return temp;
}
