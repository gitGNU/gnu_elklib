#####
#
# SYNOPSIS
#
#   AX_C___ASM__
#
# DESCRIPTION
#
#   This macro tests if the C compiler supports the __asm__ extension. Defines
#   HAVE_C__ASM__ if it is supported.
#
# LAST MODIFICATION
#
#   2007-02-18
#
# COPYLEFT
#
#   Copyright (C) 2008 Francesco Salvestrini
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#

AC_DEFUN([AX_C___ASM__], [
  AC_PREREQ([2.61])
  AC_CACHE_CHECK([if C compiler supports __asm__],
    [ax_cv_c___asm__],[
      AC_LANG_PUSH(C)
      AC_COMPILE_IFELSE([
        AC_LANG_PROGRAM([
          ],[
            __asm__("");
        ])
      ],[
        ax_cv_c___asm__=yes
      ],[
        ax_cv_c___asm__=no
      ])
      AC_LANG_POP
  ])
  AS_IF([test "$ax_cv_c___asm__" = "yes"],[
    AC_DEFINE(HAVE_C__ASM__, 1, [Define if your C compiler allows __asm__])
  ])
])
