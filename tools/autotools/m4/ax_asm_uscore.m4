#####
#
# SYNOPSIS
#
#   AX_ASM_USCORE
#
# DESCRIPTION
#
#   Checks if C symbols get an undescoreafter compiling to assembler.
#   defines HAVE_ASM_USCORE if it is found.
#
# LAST MODIFICATION
#
#  2007-02-18
#
# COPYLEFT
#
# Written by Pavel Roskin. Based on grub_ASM_EXT_C written by
# Erich Boleyn and modified by OKUJI Yoshinori
# Rearranged by <salvestrini@users.sourceforge.net>
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

AC_DEFUN([AX_ASM_USCORE], [
  AC_REQUIRE([AC_PROG_CC])
  AC_MSG_CHECKING([if C symbols get an underscore after compilation])
  AC_CACHE_VAL(ax_cv_asm_uscore,[
cat > conftest.c <<\EOF
int
func (int *list)
{
  *list = 0;
  return *list;
}
EOF

if AC_TRY_COMMAND([${CC-cc} ${CFLAGS} -S conftest.c]) && test -s conftest.s; then
  true
else
  AC_MSG_ERROR([${CC-cc} failed to produce assembly code])
fi

if grep _func conftest.s >/dev/null 2>&1; then
  ax_cv_asm_uscore=yes
else
  ax_cv_asm_uscore=no
fi

rm -f conftest*
])

  if test "x$ax_cv_asm_uscore" = xyes; then
    AC_DEFINE_UNQUOTED([HAVE_ASM_USCORE],,[Define if C symbols get an underscore after compilation])
  fi

  AC_MSG_RESULT([$ax_cv_asm_uscore])
])
