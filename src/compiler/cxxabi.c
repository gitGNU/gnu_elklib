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
#include "libc/stddef.h"
#include "compiler/compiler.h"
#include "compiler/cxxabi.h"

#if HAVE_GCC

#if 0
void __static_initialization_and_destruction_0(int a, int b)
{
	panic("__static_initialization_and_destruction_0() function called "
	      "with a = %d, b = %d\n",
	      a, b);
}

void __pure_virtual(void)
{
	panic("__pure_virtual() function called");
}
#endif

void __cxa_pure_virtual(void)
{
	panic("__cxa_pure_virtual() function called");
}

void __cxa_call_unexpected(void* exc_obj_in)
{
	unused_argument(exc_obj_in);
}

void* __cxa_begin_catch(void* exc_obj_in)
{
	unused_argument(exc_obj_in);

	return NULL;
}

void __cxa_end_catch(void)
{
}

void* __cxa_allocate_exception(size_t thrown_size)
{
	unused_argument(thrown_size);

	return NULL;
}

void __cxa_throw(void* obj,
		 void* tinfo,
		 void  (*dest) (void *))
{
	unused_argument(obj);
	unused_argument(tinfo);
	unused_argument(dest);
}

void __cxa_rethrow(void)
{
}

void _Unwind_Resume(struct _Unwind_Exception* exc)
{
	unused_argument(exc);	
}

#endif /* HAVE_GCC */
