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
#include "libc++/stack"

int main(int argc, char * argv[])
{
        try {
                std::stack<int> s;

                if (!s.empty()) {
                        return 1;
                }
                if (s.size() != 0) {
                        return 1;
                }

                s.push(1);
                s.push(2);

                if (s.empty()) {
                        return 1;
                }
                if (s.size() != 2) {
                        return 1;
                }

                (void) s.pop();

                if (s.empty()) {
                        return 1;
                }
                if (s.size() != 1) {
                        return 1;
                }

                (void) s.pop();

                if (s.size() != 0) {
                        return 1;
                }
                if (s.size() != 0) {
                        return 1;
                }

        } catch (...) {
                return 1;
        }

        return 0;
}
