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
	test-c++-exception-1			\
						\
	test-c++-clibrary-1			\
	test-c++-string-1			\
	test-c++-list-1				\
	test-c++-vector-1			\
	test-c++-memory-1			\
	test-c++-stack-1			\
	test-c++-map-1				\
	test-c++-set-1				\
	test-c++-bitset-1			\
	test-c++-deque-1			\
	test-c++-queue-1			\
						\
	test-c++-iterator-1			\
						\
	test-c++-functional-1			\
	test-c++-algorithm-1			\
	test-c++-algorithm-2			\
	test-c++-numeric-1

check_PROGRAMS =				\
	$(TESTS)

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

test_c___algorithm_2_SOURCES      = test-c++-algorithm-2.cxx
test_c___algorithm_2_LDADD        = $(TARGET_LDFLAGS)
test_c___algorithm_2_CFLAGS       = $(TARGET_CFLAGS)
test_c___algorithm_2_CXXFLAGS     = $(TARGET_CXXFLAGS)
test_c___algorithm_2_CPPFLAGS     = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___algorithm_2_CXXCPPFLAGS  = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___functional_1_SOURCES     = test-c++-functional-1.cxx
test_c___functional_1_LDADD       = $(TARGET_LDFLAGS)
test_c___functional_1_CFLAGS      = $(TARGET_CFLAGS)
test_c___functional_1_CXXFLAGS    = $(TARGET_CXXFLAGS)
test_c___functional_1_CPPFLAGS    = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___functional_1_CXXCPPFLAGS = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___numeric_1_SOURCES        = test-c++-numeric-1.cxx
test_c___numeric_1_LDADD          = $(TARGET_LDFLAGS)
test_c___numeric_1_CFLAGS         = $(TARGET_CFLAGS)
test_c___numeric_1_CXXFLAGS       = $(TARGET_CXXFLAGS)
test_c___numeric_1_CPPFLAGS       = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___numeric_1_CXXCPPFLAGS    = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

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

test_c___bitset_1_SOURCES         = test-c++-bitset-1.cxx
test_c___bitset_1_LDADD           = $(TARGET_LDFLAGS)
test_c___bitset_1_CFLAGS          = $(TARGET_CFLAGS)
test_c___bitset_1_CXXFLAGS        = $(TARGET_CXXFLAGS)
test_c___bitset_1_CPPFLAGS        = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___bitset_1_CXXCPPFLAGS     = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___deque_1_SOURCES          = test-c++-deque-1.cxx
test_c___deque_1_LDADD            = $(TARGET_LDFLAGS)
test_c___deque_1_CFLAGS           = $(TARGET_CFLAGS)
test_c___deque_1_CXXFLAGS         = $(TARGET_CXXFLAGS)
test_c___deque_1_CPPFLAGS         = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___deque_1_CXXCPPFLAGS      = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___exception_1_SOURCES      = test-c++-exception-1.cxx
test_c___exception_1_LDADD        = $(TARGET_LDFLAGS)
test_c___exception_1_CFLAGS       = $(TARGET_CFLAGS)
test_c___exception_1_CXXFLAGS     = $(TARGET_CXXFLAGS)
test_c___exception_1_CPPFLAGS     = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___exception_1_CXXCPPFLAGS  = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___map_1_SOURCES            = test-c++-map-1.cxx
test_c___map_1_LDADD              = $(TARGET_LDFLAGS)
test_c___map_1_CFLAGS             = $(TARGET_CFLAGS)
test_c___map_1_CXXFLAGS           = $(TARGET_CXXFLAGS)
test_c___map_1_CPPFLAGS           = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___map_1_CXXCPPFLAGS        = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___memory_1_SOURCES         = test-c++-memory-1.cxx
test_c___memory_1_LDADD           = $(TARGET_LDFLAGS)
test_c___memory_1_CFLAGS          = $(TARGET_CFLAGS)
test_c___memory_1_CXXFLAGS        = $(TARGET_CXXFLAGS)
test_c___memory_1_CPPFLAGS        = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___memory_1_CXXCPPFLAGS     = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___queue_1_SOURCES          = test-c++-queue-1.cxx
test_c___queue_1_LDADD            = $(TARGET_LDFLAGS)
test_c___queue_1_CFLAGS           = $(TARGET_CFLAGS)
test_c___queue_1_CXXFLAGS         = $(TARGET_CXXFLAGS)
test_c___queue_1_CPPFLAGS         = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___queue_1_CXXCPPFLAGS      = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___set_1_SOURCES            = test-c++-set-1.cxx
test_c___set_1_LDADD              = $(TARGET_LDFLAGS)
test_c___set_1_CFLAGS             = $(TARGET_CFLAGS)
test_c___set_1_CXXFLAGS           = $(TARGET_CXXFLAGS)
test_c___set_1_CPPFLAGS           = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___set_1_CXXCPPFLAGS        = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

test_c___stack_1_SOURCES          = test-c++-stack-1.cxx
test_c___stack_1_LDADD            = $(TARGET_LDFLAGS)
test_c___stack_1_CFLAGS           = $(TARGET_CFLAGS)
test_c___stack_1_CXXFLAGS         = $(TARGET_CXXFLAGS)
test_c___stack_1_CPPFLAGS         = $(TARGET_CPPFLAGS) $(TEST_CFLAGS)
test_c___stack_1_CXXCPPFLAGS      = $(TARGET_CXXCPPFLAGS) $(TEST_CXXCPPFLAGS)

##
## Maintainer related targets
##
update-local: Makefile

TESTS_SRCS =					\
	$(test_c___clibrary_1_SOURCES)		\
	$(test_c___string_1_SOURCES)		\
	$(test_c___list_1_SOURCES)		\
	$(test_c___vector_1_SOURCES)		\
	$(test_c___memory_1_SOURCES)		\
	$(test_c___stack_1_SOURCES)		\
	$(test_c___map_1_SOURCES)		\
	$(test_c___set_1_SOURCES)		\
	$(test_c___bitset_1_SOURCES)		\
	$(test_c___deque_1_SOURCES)		\
	$(test_c___queue_1_SOURCES)		\
	$(test_c___exception_1_SOURCES)		\
	$(test_c___iterator_1_SOURCES)		\
	$(test_c___functional_1_SOURCES)	\
	$(test_c___algorithm_1_SOURCES)		\
	$(test_c___numeric_1_SOURCES)

maintainer-check-whitespaces: Makefile $(TESTS_SRCS)
	$(WHITESPACE_DETECT) $(TESTS_SRCS)

maintainer-check-local: Makefile maintainer-check-whitespaces
