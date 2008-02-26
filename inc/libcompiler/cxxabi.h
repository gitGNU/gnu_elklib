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

#ifndef ELKLIB_LIBCOMPILER_CXXABI_H
#define ELKLIB_LIBCOMPILER_CXXABI_H

#include "elklib.h"
#include "libcompiler/cdefs.h"

/*
 * NOTE:
 *     Some of the entry points are intended for both C and C++, thus this
 *     header is includable from both C and C++. Though the C++ specific
 *     parts are not available in C, naturally enough.
 */

__BEGIN_DECLS

#if 0

/* Allocate array */
void* __cxa_vec_new(size_t __element_count,
		    size_t __element_size, 
		    size_t __padding_size,
		    void   (*__constructor) (void*),
		    void   (*__destructor) (void*));

void* __cxa_vec_new2(size_t __element_count,
		     size_t __element_size,
		     size_t __padding_size,
		     void (*__constructor) (void*),
		     void (*__destructor) (void*),
		     void *(*__alloc) (size_t), 
		     void (*__dealloc) (void*));

void* __cxa_vec_new3(size_t __element_count,
		     size_t __element_size,
		     size_t __padding_size,
		     void (*__constructor) (void*),
		     void (*__destructor) (void*),
		     void *(*__alloc) (size_t), 
		     void (*__dealloc) (void*, size_t));

/* Construct array */
void __cxa_vec_ctor(void*  __array_address,
		    size_t __element_count,
		    size_t __element_size,
		    void   (*__constructor) (void*),
		    void   (*__destructor) (void*));

void __cxa_vec_cctor(void*  dest_array,
		     void*  src_array,
		     size_t element_count, 
		     size_t element_size,
		     void   (*constructor) (void*, void*), 
		     void   (*destructor) (void*));
 
/* Destruct array */
void __cxa_vec_dtor(void*  __array_address,
		    size_t __element_count,
		    size_t __element_size,
		    void   (*__destructor) (void*));
  
void __cxa_vec_cleanup(void*  __array_address,
		       size_t __element_count,
		       size_t __element_size,
		       void   (*__destructor) (void*));
  
/* Destruct and release array */
void __cxa_vec_delete(void*  __array_address,
		      size_t __element_size,
		      size_t __padding_size,
		      void   (*__destructor) (void*));

void __cxa_vec_delete2(void* __array_address,
		       size_t __element_size,
		       size_t __padding_size,
		       void (*__destructor) (void*),
		       void (*__dealloc) (void*));
                  
void __cxa_vec_delete3(void* __array_address,
		       size_t __element_size,
		       size_t __padding_size,
		       void (*__destructor) (void*),
		       void (*__dealloc) (void*, size_t));

/* Exception handling */
void __cxa_bad_cast(void);
void __cxa_bad_typeid(void);

/* DSO destruction */
int __cxa_atexit(void (*)(void*), void*, void*);
int __cxa_finalize(void*);

/* Demangling routines */ 
char* __cxa_demangle(const char* __mangled_name,
		     char*       __output_buffer,
		     size_t*     __length,
		     int*        __status);

#endif

void  __cxa_call_unexpected (void* exc_obj_in);
void* __cxa_begin_catch(void* exc_obj_in);
void  __cxa_end_catch(void);
void* __cxa_allocate_exception(size_t thrown_size);
void  __cxa_throw(void* obj,
		  void* tinfo,
		  void  (*dest) (void *));
void  __cxa_rethrow(void);

struct _Unwind_Exception {
	int a;
};

void  _Unwind_Resume(struct _Unwind_Exception* exc);

/* Pure virtual functions */
void __cxa_pure_virtual(void);

__END_DECLS

#endif /* ELKLIB_LIBCOMPILER_CXXABI_H */
