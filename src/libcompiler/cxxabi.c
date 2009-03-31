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
#include "debug.h"
#include "libc/stddef.h"
#include "libcompiler/compiler.h"
#include "libcompiler/cxxabi.h"

#if HAVE_GCC

typedef char __guard;

int __cxa_guard_acquire (__guard * g)
{
	unused_argument(g);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);

	/* return !*(char *)(g); */

	return 0;
}

void __cxa_guard_release (__guard * g)
{
	unused_argument(g);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);

	/* *(char *) g = 1; */
}

void __cxa_guard_abort (__guard * g)
{
	unused_argument(g);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void __static_initialization_and_destruction_0(int a, int b)
{
	unused_argument(a);
	unused_argument(b);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void __cxa_pure_virtual(void)
{
	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void __cxa_call_unexpected(void * exc_obj_in)
{
	unused_argument(exc_obj_in);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void * __cxa_begin_catch(void * exc_obj_in)
{
	unused_argument(exc_obj_in);

	panic("Unimplemented %s function called",
	      __PRETTY_FUNCTION__);

	return NULL;
}

void __cxa_end_catch(void)
{
	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void * __cxa_allocate_exception(size_t thrown_size)
{
	unused_argument(thrown_size);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);

	return NULL;
}

void __cxa_throw(void * obj,
		 void * tinfo,
		 void   (* dest) (void *))
{
	unused_argument(obj);
	unused_argument(tinfo);
	unused_argument(dest);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void __cxa_rethrow(void)
{
	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

void _Unwind_Resume(struct _Unwind_Exception * exc)
{
	unused_argument(exc);

	panic("Unimplemented %s function called", __PRETTY_FUNCTION__);
}

#endif /* HAVE_GCC */
