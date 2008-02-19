#####
#
# SYNOPSIS
#
#   AX_C___BUILTIN_EXPECT
#
# DESCRIPTION
#
#   AX_C___BUILTIN_EXPECT checks if the compiler allows __builtin_expect()
#   Defines HAVE___BUILTIN_EXPECT if it is allowed.
#
# LAST MODIFICATION
#
#   2008-02-17
#
# COPYLEFT
#
#   Copyright (C) 2008 Francesco Salvestrini <salvestrini@users.sourceforge.net>
#   
#   This program is free software; you can redistribute it and/or
#   modify it under the terms of the GNU General Public License as
#   published by the Free Software Foundation; either version 2 of the
#   License, or (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#   General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
#   02111-1307, USA.
#
#   As a special exception, the respective Autoconf Macro's copyright
#   owner gives unlimited permission to copy, distribute and modify the
#   configure scripts that are the output of Autoconf when processing
#   the Macro. You need not follow the terms of the GNU General Public
#   License when using or distributing such scripts, even though
#   portions of the text of the Macro appear in them. The GNU General
#   Public License (GPL) does govern all other use of the material that
#   constitutes the Autoconf Macro.
#
#   This special exception to the GPL applies to versions of the
#   Autoconf Macro released by the Autoconf Macro Archive. When you
#   make and distribute a modified version of the Autoconf Macro, you
#   may extend this special exception to the GPL to apply to your
#   modified version as well.
#

AC_DEFUN([AX_C___BUILTIN_EXPECT], [
  AC_MSG_CHECKING(if compiler allows __builtin_expect)

  AC_CACHE_VAL(ax_cv_c___builtin_expect,[
    AC_LANG_PUSH([C])
    AC_COMPILE_IFELSE([
      AC_LANG_PROGRAM([
      ],[
        if (__builtin_expect(1,1)) { }
      ])
    ],[
        ax_cv_c___builtin_expect=yes
    ],[
        ax_cv_c___builtin_expect=no
    ])
    AC_LANG_POP
  ])

  AS_IF([test "x$ax_cv_c___builtin_expect" != "xno"],[
    AC_DEFINE(HAVE___BUILTIN_EXPECT,,[Define if your compile allows __builtin_expect])
  ])

  AC_MSG_RESULT($ax_cv_c___builtin_expect)
])
