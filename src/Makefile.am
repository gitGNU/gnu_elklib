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

lib_LIBRARIES =	libelk-@target_cpu@.a

noinst_HEADERS =				\
	debug.h

libc_SRCS =					\
	libc/glue.c				\
	libc/stdlib.c				\
	libc/unistd.c				\
	libc/panic.c				\
	libc/bits/byteswap.c			\
	libc/execinfo.c				\
	libc/malloc.c				\
	libc/errno.c				\
	libc/stdio.c				\
	libc/string.c				\
	libc/mcheck.c				\
	libc/ctype.c

libcxx_SRCS =					\
	libc++/glue.cxx				\
	libc++/new.cxx				\
	libc++/exception.cxx

libm_SRCS =					\
	libm/math.c

libcompiler_SRCS =				\
	libcompiler/cxxabi.c			\
	libcompiler/intmath.c			\
	libcompiler/eh_personality.cxx		\
	libcompiler/demangle.c			\
	libcompiler/demangle/libiberty.h	\
	libcompiler/demangle/ansidecl.h		\
	libcompiler/demangle/demangle.h		\
	libcompiler/demangle/cplus-dem.c	\
	libcompiler/demangle/cp-demangle.c	\
	libcompiler/demangle/cp-demangle.h	\
	libcompiler/demangle/safe-ctype.c	\
	libcompiler/demangle/safe-ctype.h	\
	libcompiler/demangle/xmalloc.c

libbfd_SRCS =					\
	libbfd/bfd.c				\
	libbfd/elf.c

COMMONCPPFLAGS += -DELKLIB_PORTED

libelk_@target_cpu@_a_ASFLAGS  = $(COMMONASFLAGS)
libelk_@target_cpu@_a_CPPFLAGS = $(COMMONCPPFLAGS)
libelk_@target_cpu@_a_CFLAGS   = $(COMMONCFLAGS)
libelk_@target_cpu@_a_CXXFLAGS = $(COMMONCXXFLAGS)
libelk_@target_cpu@_a_SOURCES  =		\
	$(libc_SRCS)				\
	$(libcxx_SRCS)				\
	$(libm_SRCS)				\
	$(libcompiler_SRCS)			\
	$(libbfd_SRCS)

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-whitespaces: $(libelk_@target_cpu@_a_SOURCES)
	$(WHITESPACE_DETECT) $(libelk_@target_cpu@_a_SOURCES)

maintainer-check-local: Makefile maintainer-check-whitespaces
