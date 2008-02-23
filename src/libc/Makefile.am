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

include $(top_srcdir)/Makefile.sub

AUTOMAKE_OPTIONS = subdir-objects

lib_LIBRARIES = libelk-c-@target_cpu@.a

libelk_c_@target_cpu@_a_CFLAGS   = $(COMMONCFLAGS)
libelk_c_@target_cpu@_a_CPPFLAGS = $(COMMONCPPFLAGS)
libelk_c_@target_cpu@_a_SOURCES  =		\
	glue.c					\
	math.c					\
	stdlib.c				\
	unistd.c				\
	bits/mman.c				\
	bits/byteswap.c				\
	bits/fcntl.c				\
	execinfo.c				\
	sys/mman.c				\
	sys/stat.c				\
	sys/fcntl.c				\
	malloc.c				\
	time.c					\
	errno.c					\
	stdio.c					\
	fcntl.c					\
	string.c				\
	mcheck.c				\
	ctype.c					\
	bcd.c
