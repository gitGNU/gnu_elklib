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
#include "libc++/list"

int main(int argc, char * argv[])
{
        std::list<int>           t;
        std::list<int>::iterator i;
        for (i = t.begin(); i != t.end(); i++) {
                // Nothing
        }

        std::list<int> L;
        L.push_back(0);
        L.push_front(1);
        L.insert(++L.begin(), 2);

        return 0;
}
