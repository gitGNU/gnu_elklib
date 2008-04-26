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
#include "debug.h"
#include "libcompiler/compiler.h"
#include "libcompiler/macro.h"
#include "libc++/cstdlib"
#include "libc++/new"
#include "libc++/exception"

using namespace ktl;

new_handler __new_handler = 0;

new_handler set_new_handler(new_handler handler)
{
        new_handler tmp;

        tmp           = __new_handler;
        __new_handler = handler;

        return tmp;
}

void * operator new(size_t size) THROW(ktl::bad_alloc)
{
        void * tmp;

        tmp = malloc(size);
        if (!tmp) {
                THROW(ktl::bad_alloc(size));
                if (__new_handler) {
                        __new_handler();
                }
        }

        return tmp;
}


void * operator new[](size_t size) THROW(ktl::bad_alloc)
{
        void * tmp;

        tmp = malloc(size);
        if (!tmp) {
                THROW(ktl::bad_alloc(size));
                if (__new_handler) {
                        __new_handler();
                }
        }

        return tmp;
}

void operator delete(void * pointer) THROW()
{
        if (pointer) {
                ktl::free(pointer);
        }
}

void operator delete[](void * pointer) THROW()
{
        if (pointer) {
                free(pointer);
        }
}

void * operator new(size_t size, void * pointer) THROW()
{
        unused_argument(size);

        return pointer;
}

void * operator new[](size_t size, void * pointer) THROW()
{
        unused_argument(size);

        return pointer;
}

void operator delete(void *, void *) THROW()
{
        missing();
}

void operator delete[](void *, void *) THROW()
{
        missing();
}
