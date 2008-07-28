/*
 * Copyright (C) 2008 Francesco Salvestrini
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
 *
 */

#ifndef ELKLIB_LIBBFD_BFD_H
#define ELKLIB_LIBBFD_BFD_H

#include "elklib.h"
#include "libc/stdint.h"
#include "libbfd/elf.h"

__BEGIN_DECLS

typedef enum {
	BFD_ELF,
} bfd_type_t;

struct bfd_image {
	bfd_type_t         type;
	union {
		bfd_elf_t  elf;
	} data;

	struct bfd_image * next;
};
typedef struct bfd_image bfd_image_t;

int  bfd_init(void);
int  bfd_image_elf_add(bfd_image_t * image,
		       Elf32_Shdr *  sh,
		       int           num,
		       int           shndx);
int  bfd_image_remove(bfd_image_t * image);
int  bfd_symbol_reverse_lookup(void *  address,
			       char *  buffer,
			       size_t  length,
			       void ** base);
void bfd_fini(void);

__END_DECLS

#endif /* ELKLIB_LIBBFD_H */
