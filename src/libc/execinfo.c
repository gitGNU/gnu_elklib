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

#include "config.h"
#include "libc/execinfo.h"
#include "libc/stddef.h"
#include "libcompiler/compiler.h"

int backtrace(void** buffer,
              int    size)
{
        unused_argument(buffer);
        unused_argument(size);

        return 0;
}

char** backtrace_symbols(void* const* buffer,
                         int          size)
{
        unused_argument(buffer);
        unused_argument(size);

        return NULL;
}
