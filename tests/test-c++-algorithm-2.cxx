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
#include "libc++/set"

int main(int argc, char * argv[])
{

        const int N = 6;
        const char* a[N] = {"isomer", "ephemeral", "prosaic", 
                            "nugatory", "artichoke", "serif"};
        const char* b[N] = {"flat", "this", "artichoke",
                            "frigate", "prosaic", "isomer"};

        std::set<const char*, ltstr> A(a, a + N);
        std::set<const char*, ltstr> B(b, b + N);
        std::set<const char*, ltstr> C;

        cout << "Set A: ";
        copy(A.begin(), A.end(), ostream_iterator<const char*>(cout, " "));
        cout << endl;
        cout << "Set B: ";
        copy(B.begin(), B.end(), ostream_iterator<const char*>(cout, " "));   
        cout << endl;

        cout << "Union: ";
        std::set_union(A.begin(), A.end(), B.begin(), B.end(),
                       ostream_iterator<const char*>(cout, " "),
                       ltstr());   
        cout << endl;

        cout << "Intersection: ";
        std::set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                              ostream_iterator<const char*>(cout, " "),
                              ltstr());    
        cout << endl;

        std::set_difference(A.begin(), A.end(), B.begin(), B.end(),
                            inserter(C, C.begin()),
                            ltstr());
        cout << "Set C (difference of A and B): ";
        copy(C.begin(), C.end(), ostream_iterator<const char*>(cout, " "));
        cout << endl;

        return 0;
}
