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

/*
 * NOTE:
 *     The following externs are useful addresses defined in the linker script,
 *     each architecture should define them in its linker related script ...
 */

extern unsigned long   _kernel;
extern unsigned long   _text;
extern unsigned long   _etext;
extern unsigned long   _data;
extern unsigned long   _edata;
extern unsigned long   _rodata;
extern unsigned long   _erodata;
extern unsigned long   _bss;
extern unsigned long   _ebss;
extern unsigned long   _debug;
extern unsigned long   _edebug;
extern unsigned long   _ekernel;

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
