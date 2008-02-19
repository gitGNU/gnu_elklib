#####
#
# SYNOPSIS
#
#   AX_C_VAR___TIME__
#
# DESCRIPTION
#
#   This macro tests if the C compiler supports the C9X standard
#   __TIME__ indentifier.
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

AC_DEFUN([AX_C_VAR___TIME__],[
  AC_REQUIRE([AC_PROG_CC])
  AC_CACHE_CHECK([whether $CC recognizes __TIME__],[ax_cv_c_var_time],[
    AC_LANG_PUSH([C])

    AC_COMPILE_IFELSE([
      AC_LANG_PROGRAM([],[ int main() { char *s = __TIME__; } ])
    ],[
      ax_cv_c_var_time=yes
    ],[
      ax_cv_c_var_time=no
    ])

    AC_LANG_POP
  ])
    
  AS_IF([test "x$ax_cv_c_var_time" != "xno"],[
    AC_DEFINE(HAVE___TIME__,,[Define to 1 if the C complier supports __TIME__])
  ])
])
