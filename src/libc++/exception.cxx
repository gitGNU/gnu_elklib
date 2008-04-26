//
// Copyright (C) 2007, 2008 Francesco Salvestrini
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#include "elklib.h"
#include "externals.h"
#include "libcompiler/compiler.h"
#include "libc++/exception"

using namespace ktl;

#if ELKLIB_EXCEPTIONS

terminate_handler  __terminate_handler  = 0;
unexpected_handler __unexpected_handler = 0;

terminate_handler set_terminate(terminate_handler handler)
{
	terminate_handler tmp;

	tmp                 = __terminate_handler;
	__terminate_handler = handler;

	return tmp;
}

unexpected_handler set_unexpected(unexpected_handler handler)
{
	unexpected_handler tmp;

	tmp                  = __unexpected_handler;
	__unexpected_handler = handler;

	return tmp;
}

void terminate()
{
	if (__terminate_handler) {
		__terminate_handler();
	}

	panic("terminate() exception handler called")
}

void unexpected()
{
	if (__unexpected_handler) {
		__unexpected_handler();
	}

	panic("unexpected() exception handler called")
}

bool uncaught_exception()
{
	return true;
}

#endif // ELKLIB_EXCEPTIONS
