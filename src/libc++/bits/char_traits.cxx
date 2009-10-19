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

#include "libc++/bits/char_traits"

namespace std {

        const char_traits<char>::char_type *
        char_traits<char>::find(const char_type * s,
                                int               n,
                                const char_type & a)
        {
                for (int i = 0; i < n; i++) {
                        if (eq(s[i], a)){
                                return (s + i);
                        }
                }

                return 0;
        }

        bool
        char_traits<char>::eq(const char_type & c1,
                              const char_type & c2)
        {
                if (strncmp(&c1, &c2, 1) == 0) {
                        return true;
                }

                return false;
        }

        char_traits<char>::char_type
        char_traits<char>::to_char_type(const int_type & i)
        {
                if (i > 0 && i <= 255) {
                        return (char)(unsigned char)i;
                }

                return 0;
        }

        const char_traits<wchar_t>::char_type *
        char_traits<wchar_t>::find(const char_type *        s,
                                   int n, const char_type & a)
        {
                for (int i = 0; i < n; i++) {
                        if (eq(s[i], a)) {
                                return (s + i);
                        }
                }

                return 0;
        }

}
