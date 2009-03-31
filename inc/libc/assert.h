/*
 * Copyright (C) 2008, 2009 Francesco Salvestrini
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

#ifndef ELKLIB_LIBC_ASSERT_H
#define ELKLIB_LIBC_ASSERT_H

#include "elklib.h"
#include "libcompiler/cdefs.h"
#include "libcompiler/macro.h"

__BEGIN_DECLS

void panic(const char* format, ...);

#ifdef NDEBUG
#define assert(EXPRESSION)
#else
#define assert(EXPRESSION)				\
	__BEGIN_MACRO					\
	if (!(EXPRESSION)) {				\
		panic("Assertion `%s' failed in "	\
		      "file %s, function %s, line %d",	\
		      #EXPRESSION,			\
		      __FILE__,				\
		      __PRETTY_FUNCTION__,		\
		      __LINE__);			\
	}						\
	__END_MACRO
#endif

__END_DECLS

#endif /* ELKLIB_LIBC_ASSERT_H */
