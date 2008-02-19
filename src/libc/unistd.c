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
#include "libc/stdio.h"
#include "libc/bits/byteswap.h"
#include "libc/assert.h"
#include "compiler/macro.h"
#include "compiler/compiler.h"

void _exit(int status)
{
	unused_argument(status);

	panic("Unimplemented");

	// halt();
}

void swab(const void* from, void* to, ssize_t n)
{
	const uint8_t * source;
	const uint8_t * source_end;
	uint8_t         junk;
	uint8_t *       dest;

	assert(from);
	assert(to);

	source     = from;
	source_end = source + (n >> 1);
	dest       = to;

	while (source < source_end) {
		junk    = *source++;
		*dest++ = bswap_16(junk);
	}
}

int getpagesize(void)
{
	panic("Unimplemented");
	//return vmm_pagesize();

	return 0;
}

int close(int fd)
{
	unused_argument(fd);

	return 0;
}

ssize_t read(int    fildes,
	     void*  buf,
	     size_t nbyte)
{
	unused_argument(fildes);
	unused_argument(buf);
	unused_argument(nbyte);

	return 0;
}

ssize_t write(int         fildes,
	      const void* buf,
	      size_t      nbyte)
{
	unused_argument(fildes);
	unused_argument(buf);
	unused_argument(nbyte);

	return 0;
}

int fsync(int fd)
{
	unused_argument(fd);

	return 0;
}
