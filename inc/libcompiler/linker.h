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

#ifndef ELKLIB_LIBCOMPILER_LINKER_H
#define ELKLIB_LIBCOMPILER_LINKER_H

#include "elklib.h"
#include "libcompiler/cdefs.h"

__BEGIN_DECLS

extern void            (*__INIT_LIST__)(void); /* C glue related */
extern void            (*__INIT_END__)(void);  /* C glue related */
extern void            (*__FINI_LIST__)(void); /* C glue related */
extern void            (*__FINI_END__)(void);  /* C glue related */
extern void            (*__CTOR_LIST__)(void); /* C++ glue related */
extern void            (*__CTOR_END__)(void);  /* C++ glue related */
extern void            (*__DTOR_LIST__)(void); /* C++ glue related */
extern void            (*__DTOR_END__)(void);  /* C++ glue related */

__END_DECLS

#endif /* ELKLIB_LIBCOMPILER_LINKER_H */
