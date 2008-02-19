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

#ifndef LIBS_COMPILER_H
#define LIBS_COMPILER_H

#include "config.h"
#include "libc/stdint.h"
#include "compiler/cdefs.h"

__BEGIN_DECLS

int demangle(const char* mangled_name,
	     char*       output_buffer,
	     size_t      output_lenght);

__END_DECLS

#endif /* LIBS_COMPILER_H */
