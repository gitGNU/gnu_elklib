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

#ifndef ELKLIB_LIBC_UNISTD_H
#define ELKLIB_LIBC_UNISTD_H

#include "elklib.h"
#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

void    _exit(int status);
void    swab(const void* from,
	     void*       to,
	     ssize_t     n);
int     getpagesize(void);
int     close(int fd);
ssize_t read(int    fildes,
	     void*  buf,
	     size_t nbyte);
ssize_t write(int        fildes,
	      const void* buf,
	      size_t      nbyte);
int     fsync(int fd);

__END_DECLS

#endif /* ELKLIB_LIBC_UNISTD_H */
