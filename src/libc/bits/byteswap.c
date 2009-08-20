/*
 * Copyright (C) 2008, 2009 Francesco Salvestrini
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "config.h"
#include "libc/unistd.h"
#include "libc/stdint.h"

uint16_t bswap_16(uint16_t x)
{
        uint16_t res;

        swab((void*) &x, (void*) &res, sizeof(uint16_t));

        return res;
}

uint32_t bswap_32(uint32_t x)
{
        uint32_t res;

        swab((void*) &x, (void*) &res, sizeof(uint32_t));

        return res;
}

#if 0
uint64_t bswap_64(uint64_t x)
{
        uint64_t res;

        swab((void*) &x, (void*) &res, sizeof(uint64_t));

        return res;
}
#endif
