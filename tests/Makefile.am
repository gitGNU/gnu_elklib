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

TESTS =						\
	test-c++-iterator-1			\
	test-c++-algorithm-1			\
	test-c++-functional-1			\
	test-c++-string-1			\
	test-c++-list-1				\
	test-c++-vector-1			\
	test-c++-clibrary-1
#TESTS +=					\
#	test-term-1

check_PROGRAMS =				\
	test-c++-iterator-1			\
	test-c++-algorithm-1			\
	test-c++-functional-1			\
	test-c++-string-1			\
	test-c++-list-1				\
	test-c++-vector-1			\
	test-c++-clibrary-1
#check_PROGRAMS +=				\
#	test-term-1

TEST_CFLAGS =  -I$(top_srcdir)/inc -I$(top_builddir)/inc
TEST_CXXCPPFLAGS = -I$(top_srcdir)/inc -I$(top_builddir)/inc

test_c___iterator_1_SOURCES       = test-c++-iterator-1.cxx
test_c___iterator_1_LDADD         = $(TARGET_LDFLAGS)
test_c___iterator_1_CFLAGS        = $(TARGET_CFLAGS)
test_c___iterator_1_CXXFLAGS      = $(TARGET_CXXFLAGS)
test_c___iterator_1_CPPFLAGS      = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___iterator_1_CXXCPPFLAGS   = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___algorithm_1_SOURCES      = test-c++-algorithm-1.cxx
test_c___algorithm_1_LDADD        = $(TARGET_LDFLAGS)
test_c___algorithm_1_CFLAGS       = $(TARGET_CFLAGS)
test_c___algorithm_1_CXXFLAGS     = $(TARGET_CXXFLAGS)
test_c___algorithm_1_CPPFLAGS     = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___algorithm_1_CXXCPPFLAGS  = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___functional_1_SOURCES     = test-c++-functional-1.cxx
test_c___functional_1_LDADD       = $(TARGET_LDFLAGS)
test_c___functional_1_CFLAGS      = $(TARGET_CFLAGS)
test_c___functional_1_CXXFLAGS    = $(TARGET_CXXFLAGS)
test_c___functional_1_CPPFLAGS    = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___functional_1_CXXCPPFLAGS = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___string_1_SOURCES         = test-c++-string-1.cxx
test_c___string_1_LDADD           = $(TARGET_LDFLAGS)
test_c___string_1_CFLAGS          = $(TARGET_CFLAGS)
test_c___string_1_CXXFLAGS        = $(TARGET_CXXFLAGS)
test_c___string_1_CPPFLAGS        = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___string_1_CXXCPPFLAGS     = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___list_1_SOURCES           = test-c++-list-1.cxx
test_c___list_1_LDADD             = $(TARGET_LDFLAGS)
test_c___list_1_CFLAGS            = $(TARGET_CFLAGS)
test_c___list_1_CXXFLAGS          = $(TARGET_CXXFLAGS)
test_c___list_1_CPPFLAGS          = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___list_1_CXXCPPFLAGS       = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___vector_1_SOURCES         = test-c++-vector-1.cxx
test_c___vector_1_LDADD           = $(TARGET_LDFLAGS)
test_c___vector_1_CFLAGS          = $(TARGET_CFLAGS)
test_c___vector_1_CXXFLAGS        = $(TARGET_CXXFLAGS)
test_c___vector_1_CPPFLAGS        = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___vector_1_CXXCPPFLAGS     = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___clibrary_1_SOURCES       = test-c++-clibrary-1.cxx
test_c___clibrary_1_LDADD         = $(TARGET_LDFLAGS)
test_c___clibrary_1_CFLAGS        = $(TARGET_CFLAGS)
test_c___clibrary_1_CXXFLAGS      = $(TARGET_CXXFLAGS)
test_c___clibrary_1_CPPFLAGS      = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___clibrary_1_CXXCPPFLAGS   = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

#test_term_1_SOURCES               =			\
#	$(top_srcdir)/src/libterm/teken_demo.c		\
#	$(top_srcdir)/src/libterm/teken.c		\
#	$(top_srcdir)/src/libterm/teken.h		\
#	$(top_srcdir)/src/libterm/teken_scs.h		\
#	$(top_srcdir)/src/libterm/teken_subr.h		\
#	$(top_srcdir)/src/libterm/teken_subr_compat.h	\
#	$(top_srcdir)/src/libterm/teken_state.h		\
#	$(top_srcdir)/src/libterm/teken_wcwidth.h
#test_term_1_LDADD                 =		\
#	$(TARGET_LDFLAGS)			\
#	$(CURSES_LIBS)				\
#	-lutil
#test_term_1_CFLAGS                =					\
#	$(TARGET_CFLAGS)						\
#	-I$(top_srcdir)/inc/libterm -I$(top_builddir)/inc/libterm	\
#	$(CURSES_CFLAGS)
#test_term_1_CXXFLAGS              = $(TARGET_CXXFLAGS)
#test_term_1_CPPFLAGS              = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
#test_term_1_CXXCPPFLAGS           = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-local: Makefile
