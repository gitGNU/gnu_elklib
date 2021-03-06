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
#include "externals.h"
#include "libc/stdarg.h"
#include "libc/stdio.h"

#define VERBOSE_PANIC 0

void panic(const char* format, ...)
{
        static char buffer[ELKLIB_PRINTF_BUFFER_LENGTH];
        va_list     args;

#if VERBOSE_PANIC
        puts("panic in progress ...");
#endif

        va_start(args, format);

        /* Secure the callee by placing a terminator */
        buffer[0] = 0;

        (void) vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);

        arch_panic(buffer);
}
