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

#include "config.h"
#include "libc/sys/mman.h"
#include "libc/stddef.h"
#include "libc/types.h"
#include "compiler/compiler.h"

void* mmap(void*  start,
	   size_t length,
	   int    prot,
	   int    flags,
	   int    fd,
	   off_t  offset)
{
	unused_argument(start);
	unused_argument(length);
	unused_argument(prot);
	unused_argument(flags);
	unused_argument(fd);
	unused_argument(offset);

	return NULL;
}

int munmap(void*  start,
	   size_t length)
{
	unused_argument(start);
	unused_argument(length);

	return 0;
}

int msync(void*  start,
	  size_t length,
	  int    flags)
{
	unused_argument(start);
	unused_argument(length);
	unused_argument(flags);

	return 0;
}
