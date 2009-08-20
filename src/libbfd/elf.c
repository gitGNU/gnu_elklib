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
#include "libc/string.h"
#include "libbfd/elf.h"
#include "libbfd/elf-format.h"
#include "libcompiler/macro.h"
#include "libcompiler/compiler.h"

int bfd_image_elf_config(bfd_elf_t *  image,
                         Elf32_Shdr * sh,
                         int          num,
                         int          shndx)
{
        int          i;
        int          j;
        Elf32_Shdr * shp;
        uint8_t *    st;

        image->sh    = sh;
        image->num   = num;
        image->shndx = shndx;

        /*
         * Find the first (and, we hope, only) SHT_SYMTAB section in
         * the file, and the SHT_STRTAB section that goes with it.
         */
        shp = sh;
        st  = (uint8_t *) shp[image->shndx].sh_addr;
        for (i = 1; i < num; i++) {
                if ((image->shndx != 0) &&
                    (image->shndx == i)) {
                        /* Skipping sections header string table */
                        continue;
                }

                if (shp[i].sh_type == SHT_SYMTAB) {
                        void * symtab;

                        if (shp[i].sh_offset == 0) {
                                continue;
                        }

                        symtab = (void *) shp[i].sh_addr;

                        /* Got the symbol table. */
                        image->symtab_start = (Elf32_Sym *)
                                ((char *) symtab);
                        image->symtab_end   = (Elf32_Sym *)
                                ((char *) symtab + shp[i].sh_size);

                        /* Find the string table to go with it */
                        j = shp[i].sh_link;
                        if (shp[j].sh_offset == 0) {
                                continue;
                        }
                        image->strtab_start = (char *)
                                shp[j].sh_addr;
                        image->strtab_end   = (char *)
                                shp[j].sh_addr + shp[j].sh_size;

                        /* There should only be one symbol table */
                        break;
                }
        }

        return 1;
}

int elf_symbol_reverse_lookup(bfd_elf_t * image,
                              void *      address,
                              char *      buffer,
                              size_t      length,
                              void **     base)
{
        Elf32_Sym * sym;
        Elf32_Sym * found_sym;
        long        delta;

        assert(image);
        assert(address);

        found_sym = NULL;
        delta     = 0x7fffffff; /* It should be enough ... */
        for (sym = image->symtab_start; sym < image->symtab_end; sym++) {
                long d;

                if (ELF32_ST_TYPE(sym->st_info) != STT_FUNC) {
                        continue;
                }
                if (sym->st_name == 0) {
                        continue;
                }

                d = (long) address - (long) sym->st_value;
                if ((d >= 0) && (d < delta)) {
                        delta     = d;
                        found_sym = sym;
                }
        }

        if (!found_sym) {
                /* No symbol found ... */
                return 0;
        }

        strncpy(buffer, image->strtab_start + found_sym->st_name, length);
        *base = (void *) found_sym->st_value;

        return 1;
}
