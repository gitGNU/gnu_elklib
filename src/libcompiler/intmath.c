/*
 * Copyright (C) 2007, 2008 Francesco Salvestrini
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
#include "debug.h"

#if HAVE_GCC

#define DIV 0
#define REM 1

static long long divremdi3(long long x,
			   long long y,
			   int       type)
{
	unsigned long long a; 
	unsigned long long b; 
	unsigned long long res;
	unsigned long long d;
	long long          result;
	long long          remainder;

	a   = (x < 0) ? -x : x;
	b   = (y < 0) ? -y : y;
	res = 0;
	d   = 1;
     
	if (b > 0) {
		while (b < a) {
			b <<= 1;
			d <<= 1;
		}
	}

	do {
		if (a >= b) {
			a   -= b;
			res += d;
		}
		b >>= 1;
		d >>= 1;
	} while (d);

	#if 0
	result    = (((x ^ y) & (1ll << 63)) == 0) ? res : -(long long)res;
	remainder = (( x      & (1ll << 63)) == 0) ? a   : -(long long)a;
	#else
	result = remainder = 0;
	#endif

	return ((type == DIV) ? result : remainder);
}

static unsigned long long udivremdi3(unsigned long long a,
				     unsigned long long b,
				     int                type)
{
	unsigned long long res;
	unsigned long long d;
	unsigned long long e;
     
	res = 0;
	d   = 1;
	/* Cast the expression in order to stop the compiler barf */
	e   = (unsigned long long) (1ll << 63);

	if (a == 0) {
		return 0;
	}

	while ((a & e) == 0) {
		e >>= 1;
	}

	if (b > 0) {
		while (b < e) {
			b <<= 1;
			d <<= 1;
		}
	}

	do {
		if (a >= b) {
			a   -= b;
			res += d;
		}
		b >>= 1;
		d >>= 1;
	} while (d);
	
	return ((type == DIV) ? res : a);
}

long long __divdi3(long long x, long long y)
{
	return divremdi3(x, y, DIV);
}

unsigned long long __udivdi3(unsigned long long x, unsigned long long y)
{
	return udivremdi3(x, y, DIV);
}


long long __moddi3(long long x, long long y)
{
	return divremdi3(x, y, REM);
}

unsigned long long __umoddi3(unsigned long long x, unsigned long long y)
{
	return udivremdi3(x, y, REM);
}

#if 0
/* ASSUME LITTLE-ENDIAN */

typedef union {
	struct {
		unsigned long low;
		unsigned long high;
	} s;
	long long ll;
} u64;

unsigned long __ucmpdi2 (unsigned long long x, unsigned long long y)
{
	u64 xu, yu;

	xu.ll = x;
	yu.ll = y;

	if (xu.s.high < yu.s.high) {
		return 0;
	} else if (xu.s.high > yu.s.high) {
		return 2;
	}

	if (xu.s.low < yu.s.low) {
		return 0;
	} else if (xu.s.low > yu.s.low) {
		return 2;
	}

	return 1;
}
#endif

#endif /* HAVE_GCC */
