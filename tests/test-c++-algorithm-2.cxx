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

struct ltstr {
        bool operator()(const char* s1, const char* s2) const {
                return strcmp(s1, s2) < 0;
        }
};

int main(int argc, char * argv[])
{
#if 0
        const int N = 6;
        const char* a[N] = { "isomer", "ephemeral", "prosaic", 
                             "nugatory", "artichoke", "serif" };
        const char* b[N] = { "flat", "this", "artichoke",
                             "frigate", "prosaic", "isomer" };

        std::set<const char*, ltstr> A(a, a + N);
        std::set<const char*, ltstr> B(b, b + N);
        std::set<const char*, ltstr> C;

        //std::cout << "Set A: ";
        std::copy(A.begin(), A.end(),
                  ostream_iterator<const char*>(std::cout, " "));
        //std::cout << endl;
        //std::cout << "Set B: ";
        std::copy(B.begin(), B.end(),
                  ostream_iterator<const char*>(std::cout, " "));   
        //std::cout << endl;

        //std::cout << "Union: ";
        std::set_union(A.begin(), A.end(), B.begin(), B.end(),
                       ostream_iterator<const char*>(std::cout, " "),
                       ltstr());   
        //std::cout << endl;

        //std::cout << "Intersection: ";
        std::set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                              ostream_iterator<const char*>(std::cout, " "),
                              ltstr());    
        //std::cout << endl;

        std::set_difference(A.begin(), A.end(), B.begin(), B.end(),
                            inserter(C, C.begin()),
                            ltstr());
        //std::cout << "Set C (difference of A and B): ";
        std::copy(C.begin(), C.end(),
                  ostream_iterator<const char*>(std::cout, " "));
        //cout << endl;
#endif

        return 0;
}
