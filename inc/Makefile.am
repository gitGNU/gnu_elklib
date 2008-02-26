##
## Input file for automake
##
## Copyright (C) 2007, 2008 Francesco Salvestrini
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##

incdestdir = $(pkgvincludedir)
nobase_incdest_HEADERS  =			\
	elklib.h				\
	debug.h					\
	libc/stdint.h				\
	libc/heap.h				\
	libc/assert.h				\
	libc/time.h				\
	libc/fcntl.h				\
	libc/float.h				\
	libc/endian.h				\
	libc/malloc.h				\
	libc/string.h				\
	libc/mcheck.h				\
	libc/stddef.h				\
	libc/bits/mman.h			\
	libc/bits/wordsize.h			\
	libc/bits/fcntl.h			\
	libc/bits/errno_values.h		\
	libc/bits/byteswap.h			\
	libc/bits/dlfnc.h			\
	libc/stdarg.h				\
	libc/ctype.h				\
	libc/execinfo.h				\
	libc/limits.h				\
	libc/math.h				\
	libc/bcd.h				\
	libc/sys/ioctl.h			\
	libc/sys/mman.h				\
	libc/sys/fcntl.h			\
	libc/sys/stat.h				\
	libc/values.h				\
	libc/stdlib.h				\
	libc/stdio.h				\
	libc/types.h				\
	libc/setjmp.h				\
	libc/unistd.h				\
	libc/param.h				\
	libc/errno.h				\
	libcompiler/cdefs.h			\
	libcompiler/compiler.h			\
	libcompiler/consistency.h		\
	libcompiler/cxxabi.h			\
	libcompiler/demangle.h			\
	libcompiler/linker.h			\
	libcompiler/macro.h

check-local:
	for i in $(nobase_incdest_HEADERS) ; do \
		if test grep config.h ; then \
			echo "Include file $i contains config.h" ; \
			exit 1 ; \
		fi ; \
	done
