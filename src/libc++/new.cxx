//
// Copyright (C) 2008, 2009 Francesco Salvestrini
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
#include "libc++/cstddef"
#include "libc++/exception"
#include "libc++/new"

using namespace std;

new_handler __new_handler = 0;

new_handler set_new_handler(new_handler h)
{
        new_handler tmp;

        tmp           = __new_handler;
        __new_handler = h;

        return tmp;
}

//
// Throw operators
//

void * operator new(std::size_t size) throw(std::bad_alloc)
{
        void * tmp = std::malloc(size);
        if (!tmp) {
                throw(std::bad_alloc());
        }

        return tmp;
}


void * operator new[](std::size_t size) throw(std::bad_alloc)
{
        void * tmp = std::malloc(size);
        if (!tmp) {
                throw(std::bad_alloc());
        }

        return tmp;
}

void operator delete(void * p) throw()
{
        if (p) {
                std::free(p);
        }
}

void operator delete[](void * p) throw()
{
        if (p) {
                std::free(p);
        }
}

//
// No-Throw operators
//

void * operator new(std::size_t s, const std::nothrow_t &) throw()
{ return std::malloc(s); }

void * operator new[](std::size_t s, const std::nothrow_t &) throw()
{ return std::malloc(s); }

void operator delete(void * p, const std::nothrow_t &) throw()
{
        if (p) {
                std::free(p);
        }
}

void operator delete[](void * p, const std::nothrow_t &) throw()
{
        if (p) {
                std::free(p);
        }
}

//
// Placement operators
//

void * operator new(std::size_t, void * p) throw()
{ return p; }

void * operator new[](std::size_t s, void * p) throw()
{ return p; }

void operator delete(void *, void *) throw()
{ }

void operator delete[](void *, void *) throw()
{ }
