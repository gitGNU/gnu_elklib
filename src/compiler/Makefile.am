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

lib_LIBRARIES = libcompiler.a

libcompiler_a_CFLAGS   = $(COMMONCFLAGS)
libcompiler_a_CPPFLAGS = $(COMMONCPPFLAGS)
libcompiler_a_SOURCES  =			\
	cdefs.h					\
	compiler.h				\
	consistency.h				\
	cxxabi.c				\
	cxxabi.h				\
	demangle.h				\
	demangle.c				\
	intmath.c				\
	macro.h
