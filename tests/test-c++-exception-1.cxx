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
#include "libc++/stdexcept"

int main(int argc, char * argv[])
{
        try {
                throw std::exception();
                throw std::bad_exception();

                throw std::logic_error("test");
                throw std::domain_error("test");
                throw std::invalid_argument("test");
                throw std::length_error("test");
                throw std::out_of_range("test");
                throw std::runtime_error("test");
                throw std::range_error("test");
                throw std::overflow_error("test");
                throw std::underflow_error("test");

        } catch (...) {
        }

        return 0;
}
