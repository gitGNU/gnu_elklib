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
#include "libc++/cstdlib"
#include "libc++/functional"
#include "libc++/algorithm"
#include "libc++/list"
#include "libc++/vector"

int main(int argc, char * argv[])
{
        {
                std::plus<int>       a1;
                std::minus<int>      a2;
                std::multiplies<int> a3;
                std::divides<int>    a4;
                std::modulus<int>    a5;
                std::negate<int>     a6;

                int tmp;

                tmp = a1(1,2);
                tmp = a2(1,2);
                tmp = a3(1,2);
                tmp = a4(1,2);
                tmp = a5(1,2);
                tmp = a6(1);
        }

        {
                std::equal_to<int>      c1;
                std::not_equal_to<int>  c2;
                std::greater<int>       c3;
                std::less<int>          c4;
                std::greater_equal<int> c5;
                std::less_equal<int>    c6;

                bool tmp;

                tmp = c1(1,2);
                tmp = c2(1,2);
                tmp = c3(1,2);
                tmp = c4(1,2);
                tmp = c5(1,2);
                tmp = c6(1,2);
        }

        {
                std::logical_and<int>  l1;
                std::logical_or<int>   l2;
                std::logical_not<int>  l3;

                bool tmp;

                tmp = l1(1,2);
                tmp = l2(1,2);
                tmp = l3(2);
        }

        {
                std::vector<double> V(100);
                std::generate(V.begin(), V.end(), rand);
        }

        {
                struct less_mag : public std::binary_function<double, double, bool> {
                        bool operator()(double x, double y)
                        { return x < y; }
                };

                std::vector<double> V(100);
                std::generate(V.begin(), V.end(), rand);

                std::sort(V.begin(), V.end(), less_mag());
        }

        {
                struct adder : public std::unary_function<double, void>
                {
                        adder() : sum(0) { }
                        double sum;
                        void operator()(double x) { sum += x; }
                };

                std::vector<double> V(100);
                std::generate(V.begin(), V.end(), rand);

                adder result = std::for_each(V.begin(), V.end(), adder());
        }

        return 0;
}
