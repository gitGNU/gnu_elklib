#####
#
# SYNOPSIS
#
#   AX_C_VAR___FILE__
#
# DESCRIPTION
#
#   This macro tests if the C compiler supports the C9X standard
#   __FILE__ indentifier.
#
# Work loosely based on ac_c_var_func macro by Christopher Currie.
#
# Copyright (C) 2008 Francesco Salvestrini
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

AC_DEFUN([AX_C_VAR___FILE__],[
  AC_REQUIRE([AC_PROG_CC])
  AC_CACHE_CHECK([whether $CC recognizes __FILE__],[ax_cv_c_var_file],[
    AC_LANG_PUSH([C])

    AC_COMPILE_IFELSE([
      AC_LANG_PROGRAM([],[ int main() { char *s = __FILE__; } ])
    ],[
      ax_cv_c_var_file=yes
    ],[
      ax_cv_c_var_file=no
    ])

    AC_LANG_POP
  ])
    
  AS_IF([test "x$ax_cv_c_var_file" != "xno"],[
    AC_DEFINE(HAVE___FILE__,,[Define to 1 if the C complier supports __FILE__])
  ])
])
