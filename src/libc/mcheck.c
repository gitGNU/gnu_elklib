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
#include "libc/malloc.h"
#include "libc/stdio.h"
#include "libc/stdlib.h"
#include "libc/heap.h"
#include "compiler/cdefs.h"

static void* (*old_malloc_hook)(size_t      size,
				const void* caller)   = 0;
static void* (*old_realloc_hook)(void*  ptr,
				 size_t size,
				 const void* caller)  = 0;
static void* (*old_memalign_hook)(size_t      alignment,
				  size_t      size,
				  const void* caller) = 0;
static void  (*old_free_hook)(void*       ptr,
			      const void* caller)     = 0;
static void  (*old_malloc_initialize_hook)(void)      = 0;
static void  (*old_after_morecore_hook)(void)         = 0;

#define RESTORE_HOOK(X) __CONCAT3(__,X,_hook)   = __CONCAT3(old_,X,_hook)
#define SAVE_HOOK(X)    __CONCAT3(old_,X,_hook) = __CONCAT3(__,X,_hook)
#define SET_HOOK(X)     __CONCAT3(__,X,_hook)   = __CONCAT3(mtrace_,X,_hook)

static void* mtrace_malloc_hook(size_t      size,
				const void* caller)
{
        void* result;
	
	RESTORE_HOOK(malloc);
	result = malloc(size);
	SAVE_HOOK(malloc);
	printf("malloc(%u) called from %p returns %p",
	       (unsigned int) size, caller, result);
	SET_HOOK(malloc);

	return result;
}

static void* mtrace_realloc_hook(void*       ptr,
				 size_t      size,
				 const void* caller)
{
        void* result;
	
	RESTORE_HOOK(realloc);
	result = realloc(ptr, size);
	SAVE_HOOK(realloc);
	printf("realloc(%p,%u) called from %p returns %p",
	       ptr, (unsigned int) size, caller, result);

	SET_HOOK(realloc);
	
	return result;
}

static void* mtrace_memalign_hook(size_t      alignment,
				  size_t      size,
				  const void* caller)
{
        void* result;
	
	RESTORE_HOOK(memalign);
	result = memalign(alignment, size);
	SAVE_HOOK(memalign);
	printf("memalign(%u,%u) called from %p returns %p",
	       alignment, size, caller, result);
	SET_HOOK(memalign);
	
	return result;
}

static void mtrace_free_hook(void*       ptr,
			     const void* caller)
{
	RESTORE_HOOK(free);
	free(ptr);
	SAVE_HOOK(free);
	printf("free(%p) called from %p",
	       ptr, caller);
	SET_HOOK(free);
}

static void mtrace_malloc_initialize_hook(void)
{
	panic("Unimplemented");
}

static void mtrace_after_morecore_hook(void)
{
	panic("Unimplemented");
}

void mtrace(void)
{
	/* Save old hooks */
	old_malloc_hook   	   = __malloc_hook;
	old_realloc_hook           = __realloc_hook;
	old_memalign_hook          = __memalign_hook;
	old_free_hook              = __free_hook;
	old_malloc_initialize_hook = __malloc_initialize_hook;
	old_after_morecore_hook    = __after_morecore_hook;

	/* Install new hooks */
	__malloc_hook            = mtrace_malloc_hook;
	__realloc_hook           = mtrace_realloc_hook;
	__memalign_hook          = mtrace_memalign_hook;
	__free_hook              = mtrace_free_hook;
	__malloc_initialize_hook = mtrace_malloc_initialize_hook;
	__after_morecore_hook    = mtrace_after_morecore_hook;
}

void muntrace(void)
{
	/* Restore old hooks */
	__malloc_hook            = old_malloc_hook;
	__realloc_hook           = old_realloc_hook;
	__memalign_hook          = old_memalign_hook;
	__free_hook              = old_free_hook;
	__malloc_initialize_hook = old_malloc_initialize_hook;
	__after_morecore_hook    = old_after_morecore_hook;
}
