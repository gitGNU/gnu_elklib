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

#ifndef BITS_DLFNC_H
#define BITS_DLFNC_H

#ifndef DLFNC_H
#error Do not use <bits/dlfnc.h> directly; include <dlfnc.h> instead
#endif

#include "config.h"

__BEGIN_DECLS

/* The MODE argument to `dlopen' contains one of the following: */
#define RTLD_LAZY         0x00001 /* Lazy function call binding.  */
#define RTLD_NOW          0x00002 /* Immediate function call binding.  */
#define RTLD_BINDING_MASK     0x3 /* Mask of binding time value.  */
#define RTLD_NOLOAD       0x00004 /* Do not load the object.  */
#define RTLD_DEEPBIND     0x00008 /* Use deep binding.  */

/*
 * If the following bit is set in the MODE argument to `dlopen',
 * the symbols of the loaded object and its dependencies are made
 * visible as if the object were linked directly into the program.
 */
#define RTLD_GLOBAL     0x00100

/*
 * Unix98 demands the following flag which is the inverse to RTLD_GLOBAL.
 * The implementation does this by default and so we can define the
 * value to zero.
 */
#define RTLD_LOCAL      0

/* Do not delete object when closed.  */
#define RTLD_NODELETE   0x01000

__END_DECLS

#endif /* BITS_DLFNC_H */
