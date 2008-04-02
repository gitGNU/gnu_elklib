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

#ifndef ELKLIB_LIBCOMPILER_COMPILER_H
#define ELKLIB_LIBCOMPILER_COMPILER_H

#include "elklib.h"
#include "libcompiler/cdefs.h"
#include "libc/stdint.h"

__BEGIN_DECLS

#ifdef HAVE___BUILTIN_EXPECT
#define likely(x)   __builtin_expect((!!(x)),1)
#define unlikely(x) __builtin_expect((!!(x)),0)
#else
#define likely(x)   (x)
#define unlikely(x) (x)
#endif

#ifdef HAVE___ATTRIBUTE__
#define ATTRIBUTE(x) __attribute__ (( x ))
#else
#define ATTRIBUTE(x)
#error __attribute__ support is needed
#endif

#ifdef HAVE___ATTRIBUTE___SECTION
#define SECTION(x)   ATTRIBUTE(section(x))
#else
#define SECTION(x)
#error __attribute__((section())) support is needed
#endif

#ifdef HAVE___ATTRIBUTE___DEPRECATED
#define DEPRECATED   ATTRIBUTE(deprecated)
#else
#define DEPRECATED
#endif

#ifdef HAVE___ATTRIBUTE___UNUSED
#define UNUSED       ATTRIBUTE(unused)
#else
#define UNUSED
#endif

#ifdef HAVE___ATTRIBUTE___NORETURN
#define NORETURN     ATTRIBUTE(noreturn)
#else
#define NORETURN
#endif

#if 0
#define unused_argument(X) do { /* Nothing */ } while (&(X) == 0)
#endif
#define unused_argument(X) ((void) (X))

__END_DECLS

#endif /* LIBELK_LIBCOMPILER_LIBS_COMPILER_H */
