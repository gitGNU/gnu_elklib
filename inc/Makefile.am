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

incdestdir = $(pkgvincludedir)

libc_HDRS =					\
	libc/stdint.h				\
	libc/heap.h				\
	libc/assert.h				\
	libc/fcntl.h				\
	libc/float.h				\
	libc/endian.h				\
	libc/malloc.h				\
	libc/string.h				\
	libc/mcheck.h				\
	libc/stddef.h				\
	libc/bits/wordsize.h			\
	libc/bits/fcntl.h			\
	libc/bits/errno_values.h		\
	libc/bits/byteswap.h			\
	libc/bits/values.h			\
	libc/bits/endian.h			\
	libc/stdarg.h				\
	libc/ctype.h				\
	libc/execinfo.h				\
	libc/limits.h				\
	libc/values.h				\
	libc/stdlib.h				\
	libc/stdio.h				\
	libc/types.h				\
	libc/unistd.h				\
	libc/param.h				\
	libc/errno.h

libcxx_HDRS =					\
	libc++/cassert				\
	libc++/cctype				\
	libc++/cerrno				\
	libc++/cfloat				\
	libc++/climits				\
	libc++/cmath				\
	libc++/cstdarg				\
	libc++/cstddef				\
	libc++/cstdio				\
	libc++/cstdlib				\
	libc++/cstring				\
	libc++/new				\
	libc++/memory				\
	libc++/limits				\
	libc++/iterator				\
	libc++/vector				\
	libc++/string				\
	libc++/list				\
	libc++/slist				\
	libc++/map				\
	libc++/stack				\
	libc++/bitset				\
	libc++/utility				\
	libc++/deque				\
	libc++/queue				\
	libc++/set				\
	libc++/algorithm			\
	libc++/functional			\
	libc++/numeric				\
	libc++/exception			\
	libc++/stdexcept			\
	libc++/bits/char_traits			\
	libc++/bits/type_traits			\
	libc++/bits/funct_exception		\
	libc++/thread				\
	libc++/mutex

libm_HDRS =					\
	libm/math.h

libcompile_HDRS =				\
	libcompiler/cdefs.h			\
	libcompiler/compiler.h			\
	libcompiler/consistency.h		\
	libcompiler/cxxabi.h			\
	libcompiler/demangle.h			\
	libcompiler/linker.h			\
	libcompiler/macro.h

libbfd_HDRS =					\
	libbfd/bfd.h				\
	libbfd/elf.h				\
	libbfd/elf-format.h

nobase_incdest_HEADERS  =			\
	elklib.h				\
	externals.h				\
	$(libc_HDRS)				\
	$(libcxx_HDRS)				\
	$(libm_HDRS)				\
	$(libcompile_HDRS)			\
	$(libbfd_HDRS)

check-includes: Makefile
	for i in $(nobase_incdest_HEADERS) ; do \
		if grep "\#include" $$i | grep "config\.h" ; then \
			echo "Header file \`$$i' must not include config.h" ; \
			exit 1 ; \
		fi ; \
	done

check-local: check-includes

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-whitespaces: Makefile $(nobase_incdest_HEADERS)
	$(WHITESPACE_DETECT) $(nobase_incdest_HEADERS)

maintainer-check-wordwraps: Makefile $(our_SRCS)
	$(WORDWRAP_DETECT) --tab-size 8 --columns 80 $(our_SRCS)

maintainer-check-guards: Makefile $(nobase_incdest_HEADERS)
	$(GUARDS_CHECK) $(nobase_incdest_HEADERS)

maintainer-check-local: Makefile		\
	maintainer-check-guards			\
	maintainer-check-whitespaces		\
	maintainer-check-wordwraps
