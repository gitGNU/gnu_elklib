#####
#
# SYNOPSIS
#
# AX_BLACKLIST_VERSION(PROGRAM,VERSION,BLACKLIST,ACTION-IF-SUCCESSFUL,ACTION-IF-NOT-SUCCESSFUL)
#
# DESCRIPTION
#
#   Check if VERSION is inside BLACKLIST. If successful execute 
#   ACTION-IF-SUCCESSFUL, ACTION-IF-NOT-SUCCESSFUL otherwise.
#
# LAST MODIFICATION
#
#  2007-02-18
#
# COPYLEFT
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

AC_DEFUN([AX_BLACKLIST_VERSION],[dnl
  AC_MSG_CHECKING([whether $1 version $2 is blacklisted ($3)])
  AS_IF([ test "`echo \"$3\" | grep \"$2\"`" = "$2" ],[
    AC_MSG_RESULT([yes])
    $4
  ],[
    AC_MSG_RESULT([no])
    $5
  ])
])
