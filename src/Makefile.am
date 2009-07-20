##
## Input file for automake
##
## Copyright (C) 2008, 2009 Francesco Salvestrini
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

lib_LIBRARIES =

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
lib_LIBRARIES +=				\
	libelk-c-@target_cpu@.a

libcxx_SRCS =					\
	libc++/glue.cxx				\
	libc++/new.cxx				\
	libc++/exception.cxx
lib_LIBRARIES +=				\
	libelk-cxx-@target_cpu@.a

libm_SRCS =					\
	libm/math.c
lib_LIBRARIES +=				\
	libelk-m-@target_cpu@.a

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
lib_LIBRARIES +=				\
	libelk-compiler-@target_cpu@.a

libbfd_SRCS =					\
	libbfd/bfd.c				\
	libbfd/elf.c
lib_LIBRARIES +=				\
	libelk-bfd-@target_cpu@.a

libterm_SRCS =					\
	libterm/teken.c				\
	libterm/teken.h				\
	libterm/teken_scs.h			\
	libterm/teken_stress.c			\
	libterm/teken_subr.h			\
	libterm/teken_subr_compat.h		\
	libterm/teken_wcwidth.h

lib_LIBRARIES +=				\
	libelk-term-@target_cpu@.a

COMMONCPPFLAGS += -DELKLIB_PORTED

libelk_c_@target_cpu@_a_ASFLAGS         = $(COMMONASFLAGS)
libelk_c_@target_cpu@_a_CPPFLAGS        = $(COMMONCPPFLAGS)
libelk_c_@target_cpu@_a_CFLAGS          = $(COMMONCFLAGS)
libelk_c_@target_cpu@_a_CXXFLAGS        = $(COMMONCXXFLAGS)
libelk_c_@target_cpu@_a_SOURCES         = $(libc_SRCS)

libelk_cxx_@target_cpu@_a_ASFLAGS       = $(COMMONASFLAGS)
libelk_cxx_@target_cpu@_a_CPPFLAGS      = $(COMMONCPPFLAGS)
libelk_cxx_@target_cpu@_a_CFLAGS        = $(COMMONCFLAGS)
libelk_cxx_@target_cpu@_a_CXXFLAGS      = $(COMMONCXXFLAGS)
libelk_cxx_@target_cpu@_a_SOURCES       = $(libcxx_SRCS)

libelk_m_@target_cpu@_a_ASFLAGS         = $(COMMONASFLAGS)
libelk_m_@target_cpu@_a_CPPFLAGS        = $(COMMONCPPFLAGS)
libelk_m_@target_cpu@_a_CFLAGS          = $(COMMONCFLAGS)
libelk_m_@target_cpu@_a_CXXFLAGS        = $(COMMONCXXFLAGS)
libelk_m_@target_cpu@_a_SOURCES         = $(libm_SRCS)

libelk_compiler_@target_cpu@_a_ASFLAGS  = $(COMMONASFLAGS)
libelk_compiler_@target_cpu@_a_CPPFLAGS = $(COMMONCPPFLAGS)
libelk_compiler_@target_cpu@_a_CFLAGS   = $(COMMONCFLAGS)
libelk_compiler_@target_cpu@_a_CXXFLAGS = $(COMMONCXXFLAGS)
libelk_compiler_@target_cpu@_a_SOURCES  = $(libcompiler_SRCS)

libelk_term_@target_cpu@_a_ASFLAGS      = $(COMMONASFLAGS)
libelk_term_@target_cpu@_a_CPPFLAGS     = $(COMMONCPPFLAGS)
libelk_term_@target_cpu@_a_CFLAGS       = $(COMMONCFLAGS)
libelk_term_@target_cpu@_a_CXXFLAGS     = $(COMMONCXXFLAGS)
libelk_term_@target_cpu@_a_SOURCES      = $(libcompiler_SRCS)

libelk_bfd_@target_cpu@_a_ASFLAGS       = $(COMMONASFLAGS)
libelk_bfd_@target_cpu@_a_CPPFLAGS      = $(COMMONCPPFLAGS)
libelk_bfd_@target_cpu@_a_CFLAGS        = $(COMMONCFLAGS)
libelk_bfd_@target_cpu@_a_CXXFLAGS      = $(COMMONCXXFLAGS)
libelk_bfd_@target_cpu@_a_SOURCES       = $(libbfd_SRCS)

libelk_SRCS =					\
	$(libc_SRCS)				\
	$(libcxx_SRCS)				\
	$(libm_SRCS)				\
	$(libcompiler_SRCS)			\
	$(libterm_SRCS)				\
	$(libbfd_SRCS)

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-whitespaces: $(libelk_SRCS)
	$(WHITESPACE_DETECT) $(libelk_SRCS)

maintainer-check-local: Makefile maintainer-check-whitespaces
