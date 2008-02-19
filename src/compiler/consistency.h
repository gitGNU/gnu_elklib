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

#ifndef COMPILER_H
#define COMPILER_H

#include "config/config.h"

/*
 * Things we need ...
 */
#ifndef HAVE_C__ASM__
#error Sorry, your compiler does not support __asm__ ...
#endif

#ifndef HAVE___ATTRIBUTE__
#error Sorry, your compiler does not support __attribute__ ...
#endif

#ifndef HAVE___ATTRIBUTE___SECTION
#error Sorry, your compiler does not support __attribute__((section)) ...
#endif

#ifndef HAVE_STRINGIZE
#error Sorry, your preprocessor does not support stringify-cation ...
#endif

#ifndef HAVE_CONCATENATION
#error Sorry, your preprocessor does not support concatenation ...
#endif

#ifndef HAVE___FILE__
#error Sorry, your preprocessor does not support __FILE__ ...
#endif

#ifndef HAVE___LINE__
#error Sorry, your preprocessor does not support __LINE__ ...
#endif

#ifndef HAVE___FUNCTION__
#error Sorry, your preprocessor does not support __FUNCTION__ ...
#endif

/*
 * XXX FIXME: Things we could wrap ... or should we remove ?
 */
#ifndef HAVE___PRETTY_FUNCTION__
/* Let us define __PRETTY_FUNCTION__ as  __FUNCTION__ ... */
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif

#endif /* COMPILER_H */
