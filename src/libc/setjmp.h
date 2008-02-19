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

#ifndef LIBC_SETJMP_H
#define LIBC_SETJMP_H

#include "config/config.h"

__BEGIN_DECLS

typedef struct __jmp_buf_tag {
#if 0
	__jmp_buf  __jmpbuf;         /* Calling environment.  */
	int        __mask_was_saved; /* Saved the signal mask?  */
	__sigset_t __saved_mask;     /* Saved signal mask.  */
#endif
} jmp_buf[1];


int setjmp(jmp_buf env);
int sigsetjmp(sigjmp_buf env, int savesigs);

__END_DECLS

#endif /* LIBC_SETJMP_H */
