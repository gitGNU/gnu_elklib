#####
#
# SYNOPSIS
#
#   AX_C_EMPTY_STRUCTS
#
# DESCRIPTION
#
#   AX_C_EMPTY_STRUCTS checks if the compiler allows empty structs.
#   Defines HAVE_EMPTY_STRUCTS if it is allowed.
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

AC_DEFUN([AX_C_EMPTY_STRUCTS], [
  AC_MSG_CHECKING(if compiler allows empty structs)

  AC_CACHE_VAL(ax_cv_c_empty_structs,[
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([
      AC_LANG_PROGRAM([
      ],[
        typedef struct { } junk;
      ])
    ],[
      ax_cv_c_empty_structs=yes
    ],[
      ax_cv_c_empty_structs=no
    ])
    AC_LANG_POP
  ])

  AS_IF([test "x$ax_cv_c_empty_structs" != "xno"],[
    AC_DEFINE(HAVE_EMPTY_STRUCTS,,[Define if your compile allows empty structs])
  ])

  AC_MSG_RESULT($ax_cv_c_empty_structs)
])

