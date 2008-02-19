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
#include "libc/sys/fcntl.h"
#include "libc/types.h"
#include "compiler/compiler.h"

int open(const char* pathname,
	 int         flags,
	 mode_t      mode)
{
	unused_argument(pathname);
	unused_argument(flags);
	unused_argument(mode);

	return 0;
}

int creat(const char* pathname,
	  mode_t      mode)
{
	unused_argument(pathname);
	unused_argument(mode);

	return 0;
}

off_t lseek(int   fildes,
	    off_t offset,
	    int   whence)
{
	unused_argument(fildes);
	unused_argument(offset);
	unused_argument(whence);

	return 0;
}
