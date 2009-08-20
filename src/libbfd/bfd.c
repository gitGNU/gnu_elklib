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
 *
 */

#include "config.h"
#include "debug.h"
#include "libc/stdint.h"
#include "libc/stdio.h"
#include "libc/stddef.h"
#include "libc/stdlib.h"
#include "libbfd/bfd.h"
#include "libbfd/elf.h"
#include "libbfd/elf-format.h"
#include "libcompiler/macro.h"
#include "libcompiler/compiler.h"

static bfd_image_t * head;

extern int elf_symbol_reverse_lookup(bfd_elf_t * image,
                                     void *      address,
                                     char *      buffer,
                                     size_t      length,
                                     void **     base);


int  bfd_image_elf_add(bfd_image_t * image,
                       Elf32_Shdr *  sh,
                       int           num,
                       int           shndx)
{
        assert(image);
        assert(sh);

        memset(image, 0, sizeof(bfd_image_t));

        image->type = BFD_ELF;

        if (!bfd_image_elf_config(&image->data.elf, sh, num, shndx)) {
                return 0;
        }

        image->next = head;
        head        = image;

        return 1;
}

int bfd_image_remove(bfd_image_t * image)
{
        bfd_image_t * p, * q;

        assert(image);

        p = NULL;
        q = head;
        while (q) {
                if (q == image) {
                        break;
                }
                p = q;
                q = q->next;
        }

        if (!p) {
                head    = head->next;
        } else {
                p->next = q->next;
        }

        return 0;
}

int bfd_symbol_reverse_lookup(void *  address,
                              char *  buffer,
                              size_t  length,
                              void ** base)
{
        bfd_image_t * p;

        p = head;
        while (p) {
                switch (p->type) {
                        case BFD_ELF:
                                if (elf_symbol_reverse_lookup(&(p->data.elf),
                                                              address,
                                                              buffer,
                                                              length,
                                                              base)) {
                                        return 1;
                                }
                                break;

                        default:
                                assert(0);
                                break;
                }

                p = p->next;
        }

        return 0;
}

int bfd_init(void)
{
        head = NULL;

        return 1;
}

void bfd_fini(void)
{
        head = NULL;
}
