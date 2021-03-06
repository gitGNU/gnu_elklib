# Process this file with autoconf to produce a configure script.

#
# configure.ac for elklib
#
# Copyright (C) 2008, 2009 Francesco Salvestrini
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

AC_INIT([ELKlib],
        m4_esyscmd([tools/maint/git-version-gen .tarball-version]),
        [elklib-generic@nongnu.org],
        [elklib],
        [http://savannah.nongnu.org/projects/elklib])

# Check for a recent version of autoconf
AC_PREREQ([2.65])

# Place/find all autotools related files in the following directories
AC_CONFIG_AUX_DIR([tools/autotools])
AC_CONFIG_MACRO_DIR([tools/autotools/m4])
AC_CONFIG_SRCDIR([src/libc/malloc.c])
AC_CONFIG_HEADERS([src/config.h])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

#
# For automake options (AM_INIT_AUTOMAKE options) see Makefile.am
# file, AUTOMAKE_OPTIONS variable
#
AM_INIT_AUTOMAKE([1.11.1 foreign std-options nostdinc -Wall color-tests])

#
# Build related programs
#
AC_PROG_MKDIR_P
AC_PROG_AWK
AC_PROG_LN_S
AC_PROG_SED
AC_PROG_GREP
AC_PROG_RANLIB

AX_PATH_MISSING([DOXYGEN],  [doxygen])
AX_PATH_MISSING([SITETOOL], [sitetool])
AX_PATH_MISSING([PERL],     [perl])
AX_PATH_MISSING([WGET],     [wget])
AX_PATH_MISSING([DNT],      [dnt])
AX_PATH_MISSING([SORT],     [sort])

# Gather supported flags while checking programs and their features
HOST_ASFLAGS=""
HOST_CPPFLAGS=""
HOST_CFLAGS=""
HOST_CXXFLAGS=""
HOST_LDFLAGS=""
HOST_LIBADD=""

TARGET_ASFLAGS=""
TARGET_CPPFLAGS=""
TARGET_CFLAGS=""
TARGET_CXXFLAGS=""
TARGET_LDFLAGS=""
TARGET_LIBADD=""

#
# Parameters
#

# C++ Support
AC_ARG_ENABLE([cxx],
  AS_HELP_STRING([--disable-cxx],[disable C++ support]),[],[])
AM_CONDITIONAL([WANT_CXX_SUPPORT],[ test "x$enable_cxx" != "xno"])
AM_COND_IF([WANT_CXX_SUPPORT],[
  AC_MSG_NOTICE([C++ support enabled])
],[
  AC_MSG_NOTICE([C++ support disabled])
])

# C++x0 Support
AC_ARG_ENABLE([cxxx0],
  AS_HELP_STRING([--disable-cxxx0],[disable C++x0 support]),[],[])
AM_CONDITIONAL([WANT_CXXX0_SUPPORT],[ test "x$enable_cxxx0" != "xno"])
AM_COND_IF([WANT_CXXX0_SUPPORT],[
  AC_MSG_NOTICE([C++x0 support enabled])
],[
  AC_MSG_NOTICE([C++x0 support disabled])
])

# SGI Support
AC_ARG_ENABLE([sgi],
  AS_HELP_STRING([--disable-sgi],[disable SGI extensions]),[],[])
AM_CONDITIONAL([WANT_SGI_SUPPORT],[ test "x$enable_sgi" != "xno"])
AM_COND_IF([WANT_SGI_SUPPORT],[
  AC_MSG_NOTICE([SGI extensions enabled])
],[
  AC_MSG_NOTICE([SGI extensions disabled])
])

# Assembler
AM_PROG_AS

# Assembler flags

# C Preprocessor
AC_PROG_CPP

# C Preprocessor flags
AX_CPP_CHECK_FLAG([-W],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -W"
])
AX_CPP_CHECK_FLAG([-Wall],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wall"
])
AX_CPP_CHECK_FLAG([-Werror],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Werror"
])
AX_CPP_CHECK_FLAG([-Wendif-labels],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wendif-labels"
])
AX_CPP_CHECK_FLAG([-Wcast-align],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wcast-align"
])
AX_CPP_CHECK_FLAG([-Wredundant-decls],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wredundant-decls"
])
AX_CPP_CHECK_FLAG([-Wswitch],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wswitch"
])
AX_CPP_CHECK_FLAG([-Wswitch-enum],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wswitch-enum"
])
AX_CPP_CHECK_FLAG([-Wparentheses],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wparentheses"
])
AX_CPP_CHECK_FLAG([-Wimplicit],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wimplicit"
])
AX_CPP_CHECK_FLAG([-Wunused],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wunused"
])
AX_CPP_CHECK_FLAG([-Wmissing-braces],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wmissing-braces"
])
AX_CPP_CHECK_FLAG([-Wreturn-type],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wreturn-type"
])
AX_CPP_CHECK_FLAG([-Wundef],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wundef"
])
AX_CPP_CHECK_FLAG([-Wswitch-default],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wswitch-default"
])
AX_CPP_CHECK_FLAG([-Wchar-subscripts],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wchar-subscripts"
])

# C compiler
AC_PROG_CC([gcc])
AS_IF([test x"$GCC" = x"yes"],[
  gcc_available=1
],[
  gcc_available=0
])
AC_DEFINE_UNQUOTED(HAVE_GCC,$gcc_available,[ Define to 1 if gcc is available ])

# C compiler version
CC_VERSION="unknown"

# Checks for gcc version, blacklist and supported flags
AS_IF([test x"$gcc_available" = x"1"],[
  AX_GCC_VERSION

  CC_VERSION=$GCC_VERSION

  AX_BLACKLIST_VERSION([gcc],$GCC_VERSION,[3.3.6],[
    AC_MSG_FAILURE([Sorry, your compiler is blacklisted.])
  ],[])

  AX_C_CHECK_FLAG([-fno-builtin],[],[],[
    HOST_CFLAGS="$HOST_CFLAGS -fno-builtin"
  ],[
  ])

  AX_C_CHECK_FLAG([-fmessage-length=0],[],[],[
    HOST_CFLAGS="$HOST_CFLAGS -fmessage-length=0"
  ],[
  ])

  AX_C_CHECK_FLAG([-fsigned-char],[],[],[
    HOST_CFLAGS="$HOST_CFLAGS -fsigned-char"
  ],[
  ])

  AX_C_CHECK_FLAG([-Wunreachable-code],[],[],[
    AX_REMOVE_FORBIDDEN(CC, [-Wunreachable-code])
  ],[
  ])

  AX_C_CHECK_FLAG([-Wsequence-point],[],[],[
    AX_REMOVE_FORBIDDEN(CC, [-Wsequence-point])
  ],[
  ])
])

AM_PROG_CC_C_O

# C++ Compiler
AC_PROG_CXX([g++])
AS_IF([test x"$CXX" = x"g++"],[
  gxx_available=1
],[
  gxx_available=0
])
AC_DEFINE_UNQUOTED(HAVE_GXX,$gxx_available,[ Define to 1 if g++ is available ])
# C compiler version
CXX_VERSION="unknown"

# Checks for g++ supported flags
AS_IF([test x"$gxx_available" = x"1"],[
  AX_GXX_VERSION

  CXX_VERSION=$GXX_VERSION

  AX_CXX_CHECK_FLAG([-fno-builtin],[],[],[
    HOST_CXXFLAGS="$HOST_CXXFLAGS -fno-builtin"
  ],[
  ])
#  AX_CXX_CHECK_FLAG([-fno-rtti],[],[],[
#    HOST_CXXFLAGS="$HOST_CXXFLAGS -fno-rtti"
#  ],[
#  ])
#  AX_CXX_CHECK_FLAG([-fno-exceptions],[],[],[
#    HOST_CXXFLAGS="$HOST_CXXFLAGS -fno-exceptions"
#  ],[
#  ])
  AX_CXX_CHECK_FLAG([-Woverloaded-virtual],[],[],[
    HOST_CXXFLAGS="$HOST_CXXFLAGS -Woverloaded-virtual"
  ],[
  ])
  AX_CXX_CHECK_FLAG([-fmessage-length=0],[],[],[
    HOST_CXXFLAGS="$HOST_CXXFLAGS -fmessage-length=0"
  ],[
  ])

  AX_REMOVE_FORBIDDEN(CXX, [-Wunreachable-code -Wsequence-point])

  AX_GCC_LIBGCC_EH(GXX_LIBGCC_EH)
  AS_IF([test -z "$GXX_LIBGCC_EH"],[
    AC_MSG_ERROR([Missing required library])
  ])
  TARGET_LIBADD="$TARGET_LIBADD $GXX_LIBGCC_EH"

  AX_GCC_LIBSUPCXX(GXX_LIBSUPCXX)
  AS_IF([test -z "$GXX_LIBSUPCXX"],[
    AC_MSG_ERROR([Missing required library])
  ])
  TARGET_LIBADD="$TARGET_LIBADD $GXX_LIBSUPCXX"
])

AC_PROG_CXX_C_O
# C++ Preprocessor
AC_PROG_CXXCPP

# C++ Preprocessor flags
AX_CXXCPP_CHECK_FLAG([-W],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -W"
])
AX_CXXCPP_CHECK_FLAG([-Wall],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wall"
])
AX_CXXCPP_CHECK_FLAG([-Werror],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Werror"
])
AX_CXXCPP_CHECK_FLAG([-Wendif-labels],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wendif-labels"
])
AX_CXXCPP_CHECK_FLAG([-Wcast-align],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wcast-align"
])
AX_CXXCPP_CHECK_FLAG([-Wredundant-decls],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wredundant-decls"
])
AX_CXXCPP_CHECK_FLAG([-Wswitch],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wswitch"
])
AX_CXXCPP_CHECK_FLAG([-Wswitch-enum],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wswitch-enum"
])
AX_CXXCPP_CHECK_FLAG([-Wparentheses],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wparentheses"
])
AX_CXXCPP_CHECK_FLAG([-Wimplicit],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wimplicit"
])
AX_CXXCPP_CHECK_FLAG([-Wunused],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wunused"
])
AX_CXXCPP_CHECK_FLAG([-Wmissing-braces],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wmissing-braces"
])
AX_CXXCPP_CHECK_FLAG([-Wreturn-type],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wreturn-type"
])
AX_CXXCPP_CHECK_FLAG([-Wundef],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wundef"
])
AX_CXXCPP_CHECK_FLAG([-Wswitch-default],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wswitch-default"
])
AX_CXXCPP_CHECK_FLAG([-Wchar-subscripts],[],[],[
  TEMP_CXXCPPFLAGS="$TEMP_CXXCPPFLAGS -Wchar-subscripts"
])

# Linker flags
HOST_LDFLAGS=""

AC_PROG_RANLIB
#AC_PROG_LIBTOOL

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_C_CONST
AC_C_VOLATILE
AC_C_STRINGIZE
AC_C_BIGENDIAN([
  AC_DEFINE(WORDS_BIGENDIAN,,[Define if your target machine is big-endian])
  target_endianess="big-endian"
],[
  AC_DEFINE(WORDS_LITTLEENDIAN,,[Define if your target machine is little-endian]
)
  target_endianess="little-endian"
],[
  AC_MSG_ERROR([target machine endianess cannot be detected ...])
])
AX_C_CONCATENATION
AX_C___ATTRIBUTE__
AX_C___ATTRIBUTE___NORETURN
AX_C___ATTRIBUTE___UNUSED
AX_C___ATTRIBUTE___DEPRECATED
AX_C___ATTRIBUTE___SECTION
AX_C___ASM__
AX_C___BUILTIN_EXPECT
AX_C_EMPTY_STRUCTS
AX_C_VAR___TIME__
AX_C_VAR___DATE__
AX_C_VAR___LINE__
AX_C_VAR___FILE__
AX_C_VAR___FUNCTION__
AX_C_VAR___PRETTY_FUNCTION__
AX_CXX_BOOL
AX_CXX_TEMPLATES
AX_CXX_EXCEPTIONS
AX_CXX_NAMESPACES
AX_CXX_RTTI
AX_CXX_DTOR_AFTER_ATEXIT
AX_CXX_STATIC_CAST
AX_CXX_DYNAMIC_CAST
AX_CXX_TYPENAME
AX_ASM_USCORE

#
# Final flags fixups
#
AX_STRING_CLEAN(HOST_ASFLAGS)
AX_STRING_CLEAN(HOST_CPPFLAGS)
AX_STRING_CLEAN(HOST_CFLAGS)
AX_STRING_CLEAN(HOST_CXXCPPFLAGS)
AX_STRING_CLEAN(HOST_CXXFLAGS)
AX_STRING_CLEAN(HOST_LDFLAGS)
AX_STRING_CLEAN(HOST_LIBADD)

#
# Architecture related fixups
#
# Make an alias of the current target cpu (it will be useful later)
AS_CASE([$target],
  [ i?86-*-* ],[ architecture="x86"  ],
  [ AC_MSG_ERROR([unknown target $target]) ]
)

# Use the alias defined before in order to define the architecture
AS_CASE([$architecture],
  [ x86  ],[
    AC_DEFINE(ARCH_X86,  1, [ 32 bit x86 architecture ])
    architecture_flags="-DARCH_X86"
  ],
  [ AC_MSG_ERROR([unknown architecture $architecture]) ]
)

TARGET_CPPFLAGS="$architecture_flags"
TARGET_CXXCPPFLAGS="$architecture_flags"

# Flags substitutions
AC_SUBST(HOST_ASFLAGS)
AC_SUBST(HOST_CPPFLAGS)
AC_SUBST(HOST_CFLAGS)
AC_SUBST(HOST_CXXCPPFLAGS)
AC_SUBST(HOST_CXXFLAGS)
AC_SUBST(HOST_LDFLAGS)
AC_SUBST(HOST_LIBADD)
AC_SUBST(TARGET_ASFLAGS)
AC_SUBST(TARGET_CPPFLAGS)
AC_SUBST(TARGET_CFLAGS)
AC_SUBST(TARGET_CXXCPPFLAGS)
AC_SUBST(TARGET_CXXFLAGS)
AC_SUBST(TARGET_LDFLAGS)
AC_SUBST(TARGET_LIBADD)

AX_SPLIT_VERSION($PACKAGE_VERSION, AX_MAJOR_VERSION, AX_MINOR_VERSION, AX_MICRO_VERSION, AX_EXTRA_VERSION)
AX_PACKAGE_API([${AX_MAJOR_VERSION}"."${AX_MINOR_VERSION}])

AC_CONFIG_FILES([
	Makefile

	docs/Makefile
	docs/info/Makefile

	inc/Makefile
	inc/elklib.h
	src/Makefile
	tests/Makefile

	site/Makefile
	site/in/Makefile

	tools/Makefile
	tools/maint/Makefile
	tools/autotools/Makefile
	tools/autotools/m4/Makefile
])

AC_CONFIG_FILES([tools/maint/fetch],               [chmod +x tools/maint/fetch])
AC_CONFIG_FILES([tools/maint/wordwrap-detect],     [chmod +x tools/maint/wordwrap-detect])
AC_CONFIG_FILES([tools/maint/whitespace-detect],   [chmod +x tools/maint/whitespace-detect])
AC_CONFIG_FILES([tools/maint/gitlog-to-committers],[chmod +x tools/maint/gitlog-to-committers])
AC_CONFIG_FILES([tools/maint/gittag-to-date],      [chmod +x tools/maint/gittag-to-date])
AC_CONFIG_FILES([tools/maint/releases-to-news],    [chmod +x tools/maint/releases-to-news])
AC_CONFIG_FILES([tools/maint/guards-check],        [chmod +x tools/maint/guards-check])

AC_OUTPUT

# Header
cat <<EOF

  ${PACKAGE_NAME} ${PACKAGE_API} (${PACKAGE_VERSION}) configuration summary

EOF

# Body
cat <<EOF
     Host CPU           : ${host_cpu} ($host)
     Build CPU          : ${build_cpu} ($build)
     Target CPU         : ${target_cpu} ($target)

     Architecture       : ${architecture}
     Target endianess   : ${target_endianess}

     Assembler          : ${CCAS}

     Preprocessor flags : ${CPPFLAGS}

     C preprocessor     : ${CPP}
     C compiler         : ${CC} (version ${CC_VERSION})
     C flags            : ${CFLAGS}

     C++ preprocessor   : ${CXXCPP}
     C++ compiler       : ${CXX} (version ${CXX_VERSION})
     C++ flags          : ${CXXFLAGS}

     Archive handler    : ${RANLIB}
EOF

# Footer
cat <<EOF

   Copyright (C) 2008, 2009 Francesco Salvestrini
   All Rights Reserved.

   The ${PACKAGE_NAME}; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The ${PACKAGE_NAME} is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   Francesco Salvestrini <salvestrini@gmail.com>

EOF
