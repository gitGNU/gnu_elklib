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
#include "externals.h"
#include "libc/stdio.h"
#include "libcompiler/linker.h"
#include "libcompiler/macro.h"

#define DEBUG_GLUE 0

#if DEBUG_GLUE
#define BANNER          "c++-glue: "

#define dprintf(F,A...) printf(BANNER F,##A)
#else
#define dprintf(F,A...)
#endif

void __do_global_ctors_aux(void)
{
	/* C++ Runtime initialization instructions */

	void (**callback)();
	int  count;

	/* Get the total number of functions to be called */
	count = &__CTOR_END__ - &__CTOR_LIST__;

	dprintf("Total constructors %d\n", count);

	callback =  &__CTOR_LIST__;
	while (count) {
		void (*ptr)() = *callback;

		assert(ptr);
		ptr();

		count--;
		callback++;
	}

	dprintf("Completed\n");
}

void __do_global_dtors_aux(void)
{
	/* C++ Runtime finalization instructions */

	void (**callback)();
	int  count;

	/* Get the total number of functions to be called */
	count = &__DTOR_END__ - &__DTOR_LIST__;

	dprintf("Total destructors %d\n", count);

	callback =  &__DTOR_LIST__;
	while (count) {
		void (*ptr)() = *callback;

		assert(ptr);
		ptr();

		count--;
		callback++;
	}

	dprintf("Completed\n");
}
