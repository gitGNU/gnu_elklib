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

#include "config.h"
#include "debug.h"
#include "libc/stdio.h"
#include "compiler/linker.h"
#include "compiler/macro.h"

#define BANNER          "c-glue: "

#define CONFIG_LIBC_DEBUG 0
#if CONFIG_LIBC_DEBUG
#define dprintf(F,A...) printf(BANNER F,##A)
#else
#define dprintf(F,A...)
#endif

void _init(void)
{
	/* C Runtime initialization instructions */

        void (**callback)();
	int  count;

	/* Get the total number of functions to be called */
        count = &__INIT_END__ - &__INIT_LIST__;

	dprintf("Total initializers %d\n", count);

        callback =  &__INIT_LIST__;
        while (count) {
                void (*ptr)() = *callback;

		assert(ptr);
                ptr();

                count--;
                callback++;
        }

	dprintf("Completed\n");
}

void _fini(void)
{
	/* C Runtime finalization instructions */

        void (**callback)();
	int  count;

	/* Get the total number of functions to be called */
        count = &__FINI_END__ - &__FINI_LIST__;

	dprintf("Total finalizers %d\n", count);

        callback =  &__FINI_LIST__;
        while (count) {
                void (*ptr)() = *callback;

		assert(ptr);
                ptr();

                count--;
                callback++;
        }

	dprintf("Completed\n");
}
