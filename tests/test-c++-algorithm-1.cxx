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
#include "libc++/cassert"
#include "libc++/algorithm"
#include "libc++/vector"

int main(int argc, char * argv[])
{
#if 0
        std::vector<int> v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        v.push_back(7);
        v.push_back(11);

        if (std::find(v.begin(), v.end(), 7) != v.end()) {
                return 1;
        }

        if (std::find(v.begin(), v.end(), 4) == v.end()) {
                return 0;
        }
#endif
        return 0;
}
