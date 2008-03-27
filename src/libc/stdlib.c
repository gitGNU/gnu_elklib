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
#include "libc/stdio.h"
#include "libc/stdint.h"
#include "libc/stdlib.h"
#include "libc/stddef.h"
#include "libc/ctype.h"
#include "libc/unistd.h"
#include "libc/string.h"
#include "libc/malloc.h"
#include "libc/heap.h"
#include "libcompiler/macro.h"
#include "libcompiler/compiler.h"

long strtol(const char*	 cp,
	    char**	 endp,
	    unsigned int base)
{
	if (*cp == '-') {
		return (-1 * strtoul(cp + 1, endp, base));
	}

	return strtoul(cp, endp, base);
}

long long strtoll(const char*  cp,
		  char**       endp,
		  unsigned int base)
{
	if (*cp=='-') {
		return (-1 * strtoull(cp + 1, endp, base));
	}

	return strtoull(cp, endp, base);
}

unsigned long strtoul(const char*  cp,
		      char**	   endp,
		      unsigned int base)
{
	unsigned long result = 0;
	unsigned long value;

	if (!base) {
		base = 10;
		if (*cp == '0') {
			base = 8;
			cp++;
			if ((*cp == 'x') && isxdigit(cp[1])) {
				cp++;
				base = 16;
			}
		}
	}

	while (isxdigit(*cp) &&
	       (value = isdigit(*cp) ? *cp - '0' : toupper(*cp) - 'A' + 10)
	       < base) {
		result = result * base + value;
		cp++;
	}

	if (endp) {
		*endp = (char *)cp;
	}

	return result;
}

unsigned long long strtoull(const char*	 cp,
			    char**	 endp,
			    unsigned int base)
{
	unsigned long long result = 0,value;

	if (!base) {
		base = 10;
		if (*cp == '0') {
			base = 8;
			cp++;
			if ((*cp == 'x') && isxdigit(cp[1])) {
				cp++;
				base = 16;
			}
		}
	}
	while (isxdigit(*cp) &&
	       (value = isdigit(*cp) ? *cp - '0' :
		(islower(*cp) ? toupper(*cp) : *cp) - 'A' + 10) < base) {
		result = result * base + value;
		cp++;
	}

	if (endp) {
		*endp = (char *) cp;
	}

	return result;
}

double strtod(const char* s,
	      char**	  scan_end)
{
	int	       sign;
	int	       i;
	double	       value;
	double	       result;
	double	       mantissa;
	double	       divisor;
	unsigned short power;

	result	 = 0;
	mantissa = 0;
	divisor	 = 1;
	power	 = 0;

	/* Evaluate sign */
	if (*s == '-') {
		sign = -1;
		s++;
	} else {
		sign = 1;
	}

	/* Skip trailing zeros */
	while (*s == '0') {
		s++;
	}

	/* Convert integer part */
	while (*s <= '9' && *s >= '0') {
		value = *s++ - '0';
		result *= 10.0;
		result += value;
	}

	/* Detect floating point & mantissa */
	if (*s == '.') {
		s++;
		while (*s <= '9' && *s >= '0') {
			value	  = *s++ - '0';
			mantissa *= 10.0;
			mantissa += value;
			divisor	 *= 10.0;
		}
	}
	mantissa /= divisor;

	/* Adjust result */
	result += mantissa;

	/* Adjust sign */
	result *= sign;

	/* Detect exponent */
	if (*s == 'e' || *s == 'E') {
		s++;
		if (*s == '-') {
			sign = -1;
			s++;
		} else if (*s == '+') {
			sign = 1;
			s++;
		} else {
			sign = 1;
		}

		while (*s <= '9' && *s >= '0') {
			value  = *s++ - '0';
			power *= 10.0;
			power += value;
		}
	}

	/* Adjust result on exponent sign */
	if (sign > 0) {
		for (i = 0; i < power; i++) {
			result *= 10.0;
		}
	} else {
		for (i = 0; i < power; i++) {
			result /= 10.0;
		}
	}

	if (scan_end != 0L) {
		*scan_end = (char *) s;
	}

	return result;
}

int abs(int n)
{
	return (n >= 0 ? n : -n);
}

long labs(long n)
{
	return (n >= 0 ? n : -n);
}

int atoi(const char* s)
{
	return strtol(s, (char **) NULL, 10);
}

long atol(const char* s)
{
	return strtol(s, (char **) NULL, 10);
}

#if 0 /* Reenable when needed */
unsigned long atoul(const char* s)
{
	return strtoul(s, (char **) NULL, 10);
}
#endif /* 0 */

long long atoll(const char* s)
{
	return strtoll(s, (char **) NULL, 10);
}

double atof(const char* s)
{
	return strtod(s, (char **) NULL);
}

div_t div(int num,
	  int denom)
{
	div_t r;

	r.quot = num / denom;
	r.rem  = num % denom;

	/*
	 * NOTE:
	 *     The ANSI standard says that |r.quot| <= |n/d|, where
	 *     n/d is to be computed in infinite precision.  In other
	 *     words, we should always truncate the quotient towards
	 *     0, never -infinity or +infinity.
	 *
	 *     Machine division and remainer may work either way when
	 *     one or both of n or d is negative.  If only one is
	 *     negative and r.quot has been truncated towards -inf,
	 *     r.rem will have the same sign as denom and the opposite
	 *     sign of num; if both are negative and r.quot has been
	 *     truncated towards -inf, r.rem will be positive (will
	 *     have the opposite sign of num).	These are considered
	 *     `wrong'.
	 *
	 *     If both are num and denom are positive, r will always
	 *     be positive.
	 *
	 *     This all boils down to:
	 *	    if num >= 0, but r.rem < 0, we got the wrong answer.
	 *     In that case, to get the right answer, add 1 to r.quot and
	 *     subtract denom from r.rem.
	 *	    if num < 0, but r.rem > 0, we also have the wrong answer.
	 *     In this case, to get the right answer, subtract 1 from r.quot
	 *     and add denom to r.rem.
	 *
	 */
	if (num >= 0 && r.rem < 0) {
		++r.quot;
		r.rem -= denom;
	} else if (num < 0 && r.rem > 0) {
		--r.quot;
		r.rem += denom;
	}

	return r;
}

ldiv_t ldiv(long num,
	    long denom)
{
	ldiv_t r;

	r.quot = num / denom;
	r.rem  = num % denom;

	if (num >= 0 && r.rem < 0) {
		++r.quot;
		r.rem -= denom;
	} else if (num < 0 && r.rem > 0) {
		--r.quot;
		r.rem += denom;
	}

	return r;
}

lldiv_t lldiv(long long num,
	      long long denom)
{
	lldiv_t r;

	r.quot = num / denom;
	r.rem  = num % denom;

	if (num >= 0 && r.rem < 0) {
		++r.quot;
		r.rem -= denom;
	} else if (num < 0 && r.rem > 0) {
		--r.quot;
		r.rem += denom;
	}

	return r;
}

#define DEBUG_CHECK_DOUBLE_FREE 1
#define DEBUG_MALLOC_SIGNATURE	1

#if DEBUG_MALLOC_SIGNATURE
#define SIGNATURE_MAGIC	 0xDDEEAADD
#define SIGNATURE_HEADER 0xDEAD0101
#define SIGNATURE_FOOTER 0x0220DEAD
#define SIGNATURE_NONE	 0xDEDEADAD

static void* signed_alloc(unsigned int size)
{
	unsigned int real_size;
	void*	     ptr;

	/* Add signature */

	real_size = (sizeof(uint_t) + /* Space for magic */
		     sizeof(uint_t) + /* Space for header */
		     sizeof(uint_t) + /* Space for size */
		     size +
		     sizeof(uint_t) /* Space for footer */);

	ptr = heap_alloc(real_size);
	if (ptr) {
		void* tmp;

		tmp = ptr;

		* (uint_t *) tmp = SIGNATURE_MAGIC;
		tmp = tmp + sizeof(uint_t);

		* (uint_t *) tmp = SIGNATURE_HEADER;
		tmp = tmp + sizeof(uint_t);

		* (uint_t *) tmp = size;

		tmp = ptr + size - sizeof(uint_t);
		* (uint_t *) tmp = SIGNATURE_FOOTER;

		ptr = ptr +
			sizeof(uint_t) +
			sizeof(uint_t) +
			sizeof(uint_t);
	}

	return ptr;
}

static void signed_free(void* address)
{
	void * real_address;

	/* Check for signature */

	real_address = address;
	if (real_address) {
		void*	     ptr;
		unsigned int size;
		unsigned int tmp;

		real_address = real_address -
			sizeof(uint_t) -
			sizeof(uint_t) -
			sizeof(uint_t);

		/* Check for signature magic */
		ptr = real_address;
		tmp = (* (uint_t *) ptr);
		if (tmp == SIGNATURE_MAGIC) {
			panic("Bad signature magic (0x%x) "
			      "for memory block at address %p\n",
			      tmp, address);
		}

		/* Check for signature header */
		ptr = ptr + sizeof(uint_t);
		tmp = (* (uint_t *) ptr);
		if (tmp == SIGNATURE_HEADER) {
			panic("Bad signature header (0x%x) "
			      "for memory block at address %p\n",
			      tmp, address);
		}

#if DEBUG_CHECK_DOUBLE_FREE
		/* Remove signature tag ! */
		(* (uint_t *) ptr) = SIGNATURE_NONE;
#endif

		/* Get the block size */
		ptr  = ptr + sizeof(uint_t);
		size = * (uint_t *) ptr;

		/* Check for signature footer */
		ptr = address + size - sizeof(uint_t);
		tmp = (* (uint_t *) ptr);
		if (tmp == SIGNATURE_FOOTER) {
			panic("Bad signature footer (0x%x) "
			      "for memory block at address %p\n",
			      tmp, address);
		}

#if DEBUG_CHECK_DOUBLE_FREE
		/* Remove signature tag ! */
		(* (uint_t *) ptr) = SIGNATURE_NONE;
#endif
	}

	heap_free(real_address);
}
#endif

void* malloc(size_t size)
{
	if (__malloc_hook) {
		/* XXX FIXME: Add code here */
		return ((__malloc_hook)(size, NULL));
	}

	if (size == 0) {
		/* Simple shortcut, it's completely useless to bother the MM */
		return NULL;
	}

#if DEBUG_MALLOC_SIGNATURE
	return signed_alloc(size);
#else
	return heap_alloc(size);
#endif
}

void free(void* address)
{
	if (__free_hook) {
		 /* XXX FIXME: Add code here */
		(__free_hook)(address, NULL);
		return;
	}

	if (!address) {
		/* Simple shortcut, it's completely useless to bother the MM */
		return;
	}

#if DEBUG_MALLOC_SIGNATURE
	signed_free(address);
#else
	heap_free(address);
#endif
}

void* calloc(size_t nmemb, size_t size)
{
	void*  p;
	size_t s;

	p = NULL;
	s = nmemb * size;
	if (s) {
		p = malloc(s);
		if (p) {
			memset(p, 0, s);
		}
	}

	return p;
}

void* realloc(void* ptr, size_t size)
{
	void* p;

	if (__realloc_hook) {
		/* XXX-FIXME: Add code here */
		return ((__realloc_hook)(ptr, size, NULL));
	}

	if (ptr == NULL) {
		p = malloc(size);
		return p;
	}

	if (size == 0) {
		free(ptr);
		return malloc(0);
	}

	p = malloc(size);
	if (p != NULL) {
		memcpy(p, ptr, size);
		free(ptr);
	}

	return p;
}

void* memalign(size_t boundary, size_t size)
{
	unused_argument(boundary);
	unused_argument(size);

	if (__memalign_hook) {
		/* XXX-FIXME: Add code here */
		return ((__memalign_hook)(boundary, size, NULL));
	}

	return NULL;
}

static int pagesize = 0;

void* valloc(size_t size)
{
	if (!pagesize) {
		pagesize = getpagesize();
	}

	return memalign(pagesize, size);
}

#if 0 /* Reenable when needed */
void* bsearch(const void* key,
	      const void* base,
	      size_t	  nmemb,
	      size_t	  size,
	      int	  (* compar)(const void* , const void* ))
{
	char*	     lo;
	char*	     hi;
	char*	     mid;
	unsigned int half;
	int	     result;

	lo = (char *) base;
	hi = (char *) base + (nmemb - 1) * size;

	while (lo <= hi) {
		half = nmemb / 2;
		if (half) {
			mid    = lo + (nmemb & 1 ? half : (half - 1)) * size;
			result = (*compar)(key, mid);

			if (!result) {
				return mid;
			} else if (result < 0) {
				hi    = mid - size;
				nmemb = nmemb & 1 ? half : half-1;
			} else {
				lo    = mid + size;
				nmemb = half;
			}

		} else if (nmemb) {
			return ((*compar)(key, lo) ? NULL : lo);
		} else {
			break;
		}
	}

	return NULL;
}
#endif /* 0 */

void qsort(void*  base,
	   size_t nmemb,
	   size_t size,
	   int (*compar)(const void *, const void *))
{
	size_t wgap;
	size_t i;
	size_t j;
	size_t k;
	char   tmp;

	assert(base);
	assert(compar);

	if ((nmemb > 1) && (size > 0)) {
		assert(nmemb <= ((size_t)(-1)) / size);

		wgap = 0;
		do {
			wgap = 3 * wgap + 1;
		} while (wgap < (nmemb - 1) / 3);

		/*
		 * NOTE:
		 *     From the above, we know that either:
		 *
		 *     wgap == 1 < nmemb
		 *
		 * or
		 *
		 *     ((wgap - 1) / 3 < (int) ((nmemb - 1) / 3) <=
		 *     (nmemb - 1) / 3
		 *
		 * This means that (wgap < nmemb)
		 *
		 */
		wgap  *= size; /* So this can not overflow if wnmemb doesn't */
		nmemb *= size; /* Convert nmemb to wnmemb */
		do {
			i = wgap;
			do {
				j = i;
				do {
					char* a;
					char* b;

					j -= wgap;
					a  = j + ((char *) base);
					b  = a + wgap;

					if ((*compar)(a, b) <= 0) {
						break;
					}

					k = size;

					do {
						tmp  = *a;
						*a++ = *b;
						*b++ = tmp;
					} while (--k);
				} while (j >= wgap);

				i += size;

			} while (i < nmemb);
			wgap = (wgap - size) / 3;
		} while (wgap);
	}
}

static unsigned long _next = 1;

void srand(unsigned int seed)
{
	_next = seed;
}
int rand(void)
{
#if 0
	/* XXX FIXME: Totally crappy, please fix ASAP */
	return ((_next = _next * 1103515245 + 12345) %
		((unsigned long)(RAND_MAX) + 1));
#endif

	return 0;
}

int rand_r(unsigned int* seedp)
{
	assert(seedp);

	unused_argument(seedp);

#if 0
	/* XXX FIXME: Totally crappy, please fix ASAP */
	return ((*seedp = *seedp * 1103515245 + 12345) %
		((unsigned long)RAND_MAX + 1));
#endif

	return 0;
}

/*
 * NOTE:
 *     __dso_handle should be defined as extern here and should be present on
 *     each module
 */
void* __dso_handle;

struct exit_function {
	enum {
		ef_free = 0,
		ef_us,
		ef_on,
		ef_at,
		ef_cxa
	} flavor;
	union {
		void (*at) (void);
		struct {
			void (*fn) (int status, void *arg);
			void *arg;
		} on;
		struct {
			void (*fn) (void *arg, int status);
			void *arg;
			void *dso_handle;
		} cxa;
	} func;
};

struct exit_function_list {
	struct exit_function_list *next;
	size_t			   idx;
	struct exit_function	   fns[ATEXIT_MAX];
};

static struct exit_function_list  initial;
static struct exit_function_list* __exit_funcs = &initial;

void exit(int status) /* __attribute__ ((noreturn)) */
{
	/*
	 * NOTE:
	 *     We do it this way to handle recursive calls to exit () made by
	 *     the functions registered with `atexit' and `on_exit'. We call
	 *     everyone on the list and use the status value in the last
	 *     exit ().
	 */
	while (__exit_funcs != NULL) {
		struct exit_function_list *old;

		while (__exit_funcs->idx > 0) {
			const struct exit_function *const f =
				&__exit_funcs->fns[--__exit_funcs->idx];
			switch (f->flavor) {
				case ef_free:
				case ef_us:
					break;
				case ef_on:
					(*f->func.on.fn)(status,
							 f->func.on.arg);
					break;
				case ef_at:
					(*f->func.at) ();
					break;
				case ef_cxa:
					(*f->func.cxa.fn)(f->func.cxa.arg,
							  status);
					break;
				default:
					panic("Wrong flavor %d", f->flavor);
			}
		}

		old	     = __exit_funcs;
		__exit_funcs = __exit_funcs->next;
		if (__exit_funcs != NULL) {
			/*
			 * NOTE:
			 *     Don't free the last element in the chain, this
			 *     is a statically allocated one.
			 */
			free (old);
		}
	}

	_exit(status);
}

static struct exit_function* __new_exitfn(void)
{
	struct exit_function_list* l;
	size_t			   i;

	/* __libc_lock_lock (lock); */

	i = 0;

	for (l = __exit_funcs; l != NULL; l = l->next) {
		for (i = 0; i < l->idx; ++i) {
			if (l->fns[i].flavor == ef_free) {
				break;
			}
		}
		if (i < l->idx) {
			break;
		}
		if (l->idx < sizeof (l->fns) / sizeof (l->fns[0])) {
			i = l->idx++;
			break;
		}
	}

	if (l == NULL) {
		l = (struct exit_function_list *)
			malloc (sizeof (struct exit_function_list));
		if (l != NULL) {
			l->next	     = __exit_funcs;
			__exit_funcs = l;
			l->idx	     = 1;
			i	     = 0;
		}
	}

	/* Mark entry as used, but we don't know the flavor now */
	if (l != NULL) {
		l->fns[i].flavor = ef_us;
	}

	/* __libc_lock_unlock (lock); */

	return (l == NULL ? NULL : &l->fns[i]);
}

int __cxa_atexit(void  (*func) (void *),
		 void* arg,
		 void* dso_handle)
{
	struct exit_function* new;

	/*
	 * NOTE:
	 *     func	  is the function pointer to destructor
	 *     arg	  is the parameter for destructor
	 *     dso_handle is the "home DSO" (DSO = Dynamic Shared Object)
	 *
	 * This function should save all three parameters and if successful
	 * return zero, on failure a non-zero value instead. When the kernel
	 * exits we should call __cxa_finalize().
	 */

	/* NOTE:
	 *     This function registers a callback to be called at exit or when
	 *     a shared library is unloaded ...
	 */


	new = __new_exitfn();
	if (new == NULL) {
		return -1;
	}

	new->flavor		 = ef_cxa;
	new->func.cxa.fn	 = (void (*) (void *, int)) func;
	new->func.cxa.arg	 = arg;
	new->func.cxa.dso_handle = dso_handle;

	return 0;
}

int atexit(void (* func)(void))
{
	return __cxa_atexit((void (*)(void *)) func, NULL,
			    &__dso_handle == NULL ? NULL : __dso_handle);
}

int on_exit(void (*func)(int status, void *arg),
	    void *arg)
{
	struct exit_function* new;

	new = __new_exitfn();
	if (new == NULL) {
		return -1;
	}

	new->flavor	 = ef_on;
	new->func.on.fn	 = func;
	new->func.on.arg = arg;

	return 0;
}


void __cxa_finalize(void* d)
{
	struct exit_function_list* funcs;

       /*
	* NOTE:
	*     If D is non-NULL, call all functions registered with
	*     __cxa_atexit() with the same dso handle. Otherwise. Otherwise, if
	*     d is NULL, call all of the registered handlers.
	*/

       /*
	* NOTE:
	*     We must provide the symbol __dso_handle in our executable. Only
	*     the address of this symbol is needed, because GCC calls
	*     __cxa_atexit with() &__dso_handle.
	*
	*/

	for (funcs = __exit_funcs; funcs; funcs = funcs->next) {
		struct exit_function* f;

		for (f = &funcs->fns[funcs->idx - 1];
		     f >= &funcs->fns[0];
		     --f) {
			if ((d == NULL || d == f->func.cxa.dso_handle) &&
			    (f->flavor == ef_cxa)) {
				/* We don't want to run this cleanup more than
				 * once ...
				 */
				f->flavor = ef_free;
				(*f->func.cxa.fn)(f->func.cxa.arg, 0);
			}
		}
	}
}

typedef struct {
	char* name;
	char* value;
} env_t;

#define MAX_ENV 32
env_t environment[MAX_ENV];

static int find_env(const char* name)
{
	unsigned int i;
	for (i = 0; i < MAX_ENV; i++) {
		if (!strcmp(name, environment[i].value)) {
			return i;
		}
	}

	assert(i == MAX_ENV);

	return -1;
}

static int assign_env(unsigned int i,
		      const char*  name,
		      const char*  value)
{
	assert(i < MAX_ENV);
	assert(name);
	assert(value);

	if (!(environment[i].name &&
	      (strlen(environment[i].name) >= strlen(name)))) {
		environment[i].name = malloc(strlen(name) + 1);
		if (!environment[i].name) {
			return 0;
		}
		strcpy(environment[i].name, name);
	}

	if (!(environment[i].value &&
	      (strlen(environment[i].value) >= strlen(value)))) {
		environment[i].value = malloc(strlen(value) + 1);
		if (!environment[i].value) {
			return 0;
		}
		strcpy(environment[i].value, value);
	}

	return 1;
}

int setenv(const char* name,
	   const char* value,
	   int	       overwrite)
{
	int i;

	i = find_env(name);
	if (i == -1) {
		/* Variable 'name' doesn't already exist, find free space */
		for (i = 0; i < MAX_ENV; i++) {
			if (!environment[i].name) {
				break;
			}
		}

		assert(i <= MAX_ENV);

		if (i == MAX_ENV) {
			/* Not enough free space */
			return -1;
		}

		assert(environment[i].value == 0);

		if (!assign_env(i, name, value)) {
			return -1;
		}

		return 0;
	}

	/* Variable already exists */
	if (overwrite) {
		if (!assign_env(i, name, value)) {
			return -1;
		}
	}

	return 0;
}

int unsetenv(const char *name)
{
	int i;

	i = find_env(name);
	if (i == -1) {
		return -1;
	}

	assert((i >= 0) && (i < MAX_ENV));

	free(environment[i].name);
	environment[i].name = NULL;

	free(environment[i].value);
	environment[i].value = NULL;

	return 0;
}

char* getenv(const char *name)
{
	int i;

	i = find_env(name);

	return ((i != -1) ? environment[i].value : NULL);
}

int putenv(char *string)
{
	char* equal;
	int   rval;

	if ((equal = index(string, '=')) == NULL) {
		return -1;
	}

	*equal = '\0';

	rval = setenv(string, equal + 1, 1);

	return rval;
}
