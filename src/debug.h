/*
 * Copyright (C) 2007, 2008 Francesco Salvestrini
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

#ifndef DEBUG_H
#define DEBUG_H

#include "config.h"
#include "libc/stdio.h"
#include "libc/assert.h"

__BEGIN_DECLS

void panic(const char* format, ...);

/*
 * NOTE:
 *     Nobody should remove bug(), unpredictable results will happen ...
 */
#define bug()					\
	__BEGIN_MACRO				\
	panic("Bug found in '%s' line %d",	\
	       __PRETTY_FUNCTION__,__LINE__);	\
	__END_MACRO

#define missing()					\
	__BEGIN_MACRO					\
	printf("Missing code in '%s' line %d\n",	\
	       __PRETTY_FUNCTION__,__LINE__);		\
	__END_MACRO

/* The user has the option to cut-off expect() calls */
#define CONFIG_EXPECT 1
#if CONFIG_EXPECT
#define expect(EXPRESSION)   assert(EXPRESSION)
#else
#define expect(EXPRESSION)
#endif

__END_DECLS

#endif /* DEBUG_H */
