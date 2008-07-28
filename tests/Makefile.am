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

TESTS =						\
	test-c++-list-1				\
	test-c++-vector-1			\
	test-c++-clibrary-1

check_PROGRAMS =				\
	test-c++-list-1				\
	test-c++-vector-1			\
	test-c++-clibrary-1

TEST_CFLAGS =  -I$(top_srcdir)/inc -I$(top_builddir)/inc
TEST_CXXCPPFLAGS = -I$(top_srcdir)/inc -I$(top_builddir)/inc

test_c___list_1_SOURCES       = test-c++-list-1.cxx
test_c___list_1_LDADD         = $(TARGET_LDFLAGS)
test_c___list_1_CFLAGS        = $(TARGET_CFLAGS)
test_c___list_1_CXXFLAGS      = $(TARGET_CXXFLAGS)
test_c___list_1_CPPFLAGS      = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___list_1_CXXCPPFLAGS   = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___vector_1_SOURCES     = test-c++-vector-1.cxx
test_c___vector_1_LDADD       = $(TARGET_LDFLAGS)
test_c___vector_1_CFLAGS      = $(TARGET_CFLAGS)
test_c___vector_1_CXXFLAGS    = $(TARGET_CXXFLAGS)
test_c___vector_1_CPPFLAGS    = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___vector_1_CXXCPPFLAGS = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___clibrary_1_SOURCES     = test-c++-clibrary-1.cxx
test_c___clibrary_1_LDADD       = $(TARGET_LDFLAGS)
test_c___clibrary_1_CFLAGS      = $(TARGET_CFLAGS)
test_c___clibrary_1_CXXFLAGS    = $(TARGET_CXXFLAGS)
test_c___clibrary_1_CPPFLAGS    = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___clibrary_1_CXXCPPFLAGS = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-local: Makefile