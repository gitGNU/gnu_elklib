#####
#
# SYNOPSIS
#
#   AX_C_CONCATENATION
#
# DESCRIPTION
#
#   Provides a test for the compiler support of concatenation.
#   defines HAVE_CONCATENATION if it is found.
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

AC_DEFUN([AX_C_CONCATENATION], [
  AC_MSG_CHECKING(if compiler supports concatenation)

  AC_CACHE_VAL(ax_cv_concatenation,[
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([
      AC_LANG_PROGRAM([[
        #define MACRO(PARM1,PARM2,PARM3) char* PARM1##PARM2##PARM3;
      ]],
      [
        MACRO(This,Is,AString);
      ])
    ],[
        ax_cv_concatenation=yes
    ],[
        ax_cv_concatenation=no
    ])
    AC_LANG_POP
  ])

  AS_IF([test "x$ax_cv_concatenation" != "xno"],[
    AC_DEFINE(HAVE_CONCATENATION,,[Define if your compiler support concatenation])
  ])

  AC_MSG_RESULT($ax_cv_concatenation)
])
