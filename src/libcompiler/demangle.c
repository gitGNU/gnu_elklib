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
#include "libc/stdint.h"
#include "libc/string.h"
#include "libc/ctype.h"
#include "libcompiler/cdefs.h"

#define BANNER          "demangle: "

#define CONFIG_SYMBOLS_DEMANGLING_DEBUG 0
#define CONFIG_SYMBOLS_DEMANGLING       0

#if CONFIG_SYMBOLS_DEMANGLING_DEBUG
#define dprintf(F,A...) printf(BANNER F,##A)
#else
#define dprintf(F,A...)
#endif

#if HAVE_GCC

#if CONFIG_SYMBOLS_DEMANGLING
typedef struct {
	const char*  buffer;
	size_t       length;
	size_t       position;
} demangle_instream_t;

typedef struct {
	char*        buffer;
	size_t       length;
	size_t       position;
} demangle_outstream_t;

typedef struct {
	demangle_instream_t input;

	enum {
		D_NONE,
		D_SOURCE,
		D_OPERATOR,
		D_CONSTRUCTOR,
		D_DESTRUCTOR,
	} last_seen;

	demangle_outstream_t output;
} demangle_data_t;

/* Utilities */
static void char_put(demangle_data_t* data, char c)
{
	assert(data);

	if (data->output.position < data->output.length) {
		data->output.buffer[data->output.position] = c;
		data->output.position++;
		
		/* dprintf("put value = '%c'\n", c); */
	}
}

static void string_put(demangle_data_t* data, char* s)
{
	int i;

	assert(data);

	for (i = 0; s[i] != 0; i++) {
		char_put(data, s[i]);
	}

	/* dprintf("wrote value = '%s'\n", s); */
}

static char char_get(demangle_data_t* data)
{
	char c;

	c = 0;

	assert(data);

	if (data->input.position < data->input.length) {
		c = data->input.buffer[data->input.position];
		data->input.position++;
	}

	/* dprintf("got value = '%c'\n", c); */
	return c;
}

static char char_peek(demangle_data_t* data)
{
	char c;

	c = 0;

	assert(data);

	if (data->input.position < data->input.length) {
		c = data->input.buffer[data->input.position];
	}

	/* dprintf("peek value = '%c'\n", c); */
	return c;
}

static void char_skip(demangle_data_t* data, unsigned int delta)
{
	unsigned int count;

	assert(data);

	count = delta;
	while (count) {
		if (data->input.position < data->input.length) {
			data->input.position++;
		} else {
			break;
		}
		count--;
	}
}

/* Demangling utilities */
static long demangle_number(demangle_data_t* data);
static int  demangle_cv_qualifiers(demangle_data_t* data, int member);
static int  demangle_substitution(demangle_data_t*data);
static int  demangle_template_args(demangle_data_t* data);
static int  demangle_template_param(demangle_data_t* data);
static int  demangle_prefix(demangle_data_t* data);
static int  demangle_nested_name(demangle_data_t* data);
static int  demangle_discriminator(demangle_data_t* data);
static int  demangle_special_name(demangle_data_t* data);
static int  demangle_name(demangle_data_t* data);
static int  demangle_encoding(demangle_data_t* data);
static int  demangle_local_name(demangle_data_t* data);
static int  demangle_substitution_name(demangle_data_t* data);
static int  demangle_identifier(demangle_data_t* data, unsigned int length);
static int  demangle_source_name(demangle_data_t* data);
static int  demangle_operator_name(demangle_data_t* data);
static int  demangle_ctor_name(demangle_data_t* data);
static int  demangle_dtor_name(demangle_data_t* data);
static int  demangle_unqualified_name(demangle_data_t* data);

static long demangle_number(demangle_data_t* data)
{
	int  negative;
	char peek;
	long ret;

	dprintf("Demangling number\n");

	negative = 0;
	peek     = char_peek(data);
	if (peek == 'n') {
		negative = 1;
		char_skip(data, 1);
		peek     = char_peek(data);
	}
	
	ret = 0;
	while (1) {
		if (!isdigit(peek)) {
			if (negative) {
				ret = - ret;
			}
			return ret;
		}
		
		ret = ret * 10 + peek - '0';
		char_skip(data, 1);
		peek = char_peek(data);
	}
}

static int demangle_cv_qualifiers(demangle_data_t* data, int member)
{
	assert(data);
	assert(member);

	unused_argument(data);
	unused_argument(member);

	dprintf("Demangling cv qualifiers for %p with member %d\n",
		data, member);

	return 1;
}

static int demangle_substitution(demangle_data_t* data)
{
	assert(data);

	unused_argument(data);

	dprintf("Demangling substitution for %p\n", data);

	return 1;
}

static int demangle_template_args(demangle_data_t* data)
{
	assert(data);

	unused_argument(data);

	dprintf("Demangling template arguments for %p\n", data);

	return 1;
}

static int demangle_template_param(demangle_data_t* data)
{
	assert(data);

	unused_argument(data);

	dprintf("Demangling template param for %p\n", data);

	return 1;
}

static int demangle_prefix(demangle_data_t* data)
{
	assert(data);

	dprintf("Demangling prefix for %p\n", data);

	while (1) {
		char peek;

		peek = char_peek(data);
		if (peek == 0) {
			dprintf("Demangling prefix (empty peek)\n");
			return 0;
		}

		if (isdigit(peek) ||
		    islower(peek) ||
		    peek == 'C'   ||
		    peek == 'D') {
			demangle_unqualified_name(data);
		} else if (peek == 'S') {
			demangle_substitution(data);
		} else if (peek == 'I') {
			demangle_template_args(data);
		} else if (peek == 'T') {
			demangle_template_param(data);
		} else if (peek == 'E') {
			dprintf("Demangling prefix (completed)\n");
			return 1;
		} else {
			dprintf("Demangling prefix (?)\n");
			return 1;
		}
	}
	
	/* return 1; */
}

static int demangle_nested_name(demangle_data_t* data)
{
	assert(data);

	dprintf("Demangling nested name for %p\n", data);

	if (!demangle_cv_qualifiers(data, 1)) {
		return 0;
	}
	if (!demangle_prefix(data)) {
		return 0;
	}

	if (char_get(data) != 'E') {
		dprintf("Nested name is not completed\n");
		return 0;
	}
	
	return 1;
}

static int demangle_discriminator(demangle_data_t* data)
{
	long discrim;

	dprintf("Demangling discriminator for %p\n", data);

	assert(data);

	if (char_peek(data) != '_') {
		return 1;
	}
	char_skip(data, 1);
	discrim = demangle_number(data);
	if (discrim < 0) {
		return 0;
	}

	return 1;
}

static int demangle_special_name(demangle_data_t* data)
{
	assert(data);

	unused_argument(data);

	dprintf("Demangling special name for %p\n", data);

	return 0;
}

static int demangle_name(demangle_data_t* data)
{
	char c;
	int  retval;

	assert(data);

	dprintf("Demangling name for %p\n", data);

	retval = 0;
	c      = char_get(data);
	switch (c) {
		case 'N':
			retval = demangle_nested_name(data);
			break;
		case 'Z':
			retval = demangle_local_name(data);
			break;
		case 'S':
			retval = demangle_substitution_name(data);
			break;
		default:
			retval = demangle_unqualified_name(data);
			break;
	}

	return retval;
}

static int demangle_encoding(demangle_data_t* data)
{
	char c;

	assert(data);

	dprintf("Demangling encoding for %p\n", data);

	c = char_peek(data);
	if (c == 'G' || c == 'T') {
		return demangle_special_name(data);
	}

	return demangle_name(data);
}

static int demangle_local_name(demangle_data_t* data)
{
	char c;

	assert(data);

	dprintf("Demangling local name for %p\n", data);

	demangle_encoding(data);
	c = char_get(data);
	if (c != 'E') {
		return 0;
	}
	c = char_peek(data);
	if (c == 's') {
		char_skip(data, 1);
		if (!demangle_discriminator(data)) {
			return 0;
		}
	} else {
		demangle_name(data);
		if (!demangle_discriminator(data)) {
			return 0;
		}
	}
	
	return 1;
}

static int demangle_substitution_name(demangle_data_t* data)
{
	assert(data);

	unused_argument(data);

	dprintf("Demangling substitution name for %p\n", data);

	return 0;
}

static int demangle_identifier(demangle_data_t* data, unsigned int length)
{
	unsigned int count;

	assert(data);

	dprintf("Demangling identifier for %p, length %d\n", data, length);

	count = length;
	while (count) {
		char_put(data, char_get(data));
		count--;
	}

	return 1;
}

static int demangle_source_name(demangle_data_t* data)
{
	long len;
	
	assert(data);

	dprintf("Demangling source name for %p\n");

	if (data->last_seen != D_NONE) {
		string_put(data, "::");
	}
	data->last_seen = D_SOURCE;

	len = demangle_number(data);
	if (len <= 0) {
		return 0;
	}

	return demangle_identifier(data, (unsigned int) len);
}

static int demangle_operator_name(demangle_data_t* data)
{
	assert(data);

	dprintf("Demangling operator name for %p\n", data);

	data->last_seen = D_OPERATOR;
	return 0;
}

static int demangle_ctor_name(demangle_data_t* data)
{
	char c;
	int  retval;

	assert(data);

	dprintf("Demangling ctor name for %p\n", data);
	data->last_seen = D_CONSTRUCTOR;

	retval = 0;
	c      = char_peek(data);
#if 0
	switch (c) {
		case '1':
			retval = 0;
			break;
		case '2':
			retval = 0;
			break;
		case '3':
			retval = 0;
			break;
		default:
			retval = 0;
			break;
	}
#endif
	return retval;
}

static int demangle_dtor_name(demangle_data_t* data)
{
	char c;
	int  retval;
	
	assert(data);

	dprintf("Demangling dtor name for %p\n", data);
	data->last_seen = D_DESTRUCTOR;

	retval = 0;
	c      = char_peek(data);
#if 0
	switch (c) {
		case '1':
			retval = 0;
			break;
		case '2':
			retval = 0;
			break;
		case '3':
			retval = 0;
			break;
		default:
			retval = 0;
			break;
	}
#endif
	return retval;
}

static int demangle_unqualified_name(demangle_data_t* data)
{
	char c;
	
	assert(data);

	dprintf("Demangling unqualified name for %p\n", data);

	c = char_peek(data);
	if (c) {
		if (isdigit(c)) {
			return demangle_source_name(data);
		} else if (islower(c)) {
			return demangle_operator_name(data);
		} else if (c == 'C') {
			return demangle_ctor_name(data);
		} else if (c == 'D') {
			return demangle_dtor_name(data);
		}
	}

	return 0;
}

static int demangle_all(demangle_data_t* data)
{
	assert(data);

	dprintf("Demangling all for %p\n", data);

	if (char_get(data) != '_') {
		return 0;
	}
	if (char_get(data) != 'Z') {
		return 0;
	}

	return demangle_encoding(data);
}

/* This should be the only exported function */
int demangle(const char* mangled_name,
	     char*       output_buffer,
	     size_t      output_length)
{
	demangle_data_t data;

	assert(mangled_name);

	data.input.buffer    = mangled_name;
	data.input.length    = strlen(mangled_name);
	data.input.position  = 0;

	data.last_seen       = D_NONE;

	assert(output_buffer);
	assert(output_length > 0);

	data.output.buffer   = output_buffer;
	data.output.length   = output_length;
	data.output.position = 0;

	return demangle_all(&data);
}
#endif /* CONFIG_SYMBOLS_DEMANGLING */

#endif /* HAVE_GCC */
