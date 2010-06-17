##
## Input file for automake
##
## Copyright (C) 2008, 2009 Francesco Salvestrini
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##

include $(top_srcdir)/Makefile.sub

EXTRA_DIST =
BUILT_SOURCES =
CLEANFILES =
MAINTAINERCLEANFILES =

include $(top_srcdir)/Makefile.top

ACLOCAL_AMFLAGS = -I tools/autotools/m4 --install

SUBDIRS =					\
	tools					\
	inc					\
	src					\
	tests					\
	.					\
	docs					\
	site

##
## NOTE:
##     Options listed in AUTOMAKE_OPTIONS variable are applied on a
##     per-`Makefile' basis.
##
AUTOMAKE_OPTIONS = check-news

##
## NOTE:
##     Makefile.am included files are automatically distributed by automake
##     rules
##
EXTRA_DIST +=					\
	README COPYING INSTALL THANKS		\
	bootstrap .bootstrap

##
## Place handy configuration tool somewhere in the system
##
EXTRA_DIST +=					\
	elklib-config.in			\
	elklib-config-arch.in

bin_SCRIPTS = elklib-config elklib-config-@target_cpu@

all-local: elklib-config elklib-config-@target_cpu@

elklib-config: $(srcdir)/elklib-config.in Makefile
	( rm -f $@ $@.tmp && \
	   $(do_subst) < $(srcdir)/elklib-config.in > $@.tmp && \
	   chmod +x $@.tmp && \
	   chmod a-w $@.tmp && \
	   mv -f $@.tmp $@ ) || { \
		 rm -f $@ $@.tmp ; \
		 exit 1 ; \
	}
CLEANFILES += elklib-config

elklib-config-@target_cpu@: $(srcdir)/elklib-config-arch.in Makefile
	( rm -f $@ $@.tmp && \
	   $(do_subst) < $(srcdir)/elklib-config-arch.in > $@.tmp && \
	   chmod +x $@.tmp && \
	   chmod a-w $@.tmp && \
	   mv -f $@.tmp $@ ) || { \
		 rm -f $@ $@.tmp ; \
		 exit 1 ; \
	}
CLEANFILES += elklib-config-@target_cpu@

##
## Miscellaneous targets
##
doxygen: all
	(cd docs && $(MAKE) $(AM_MAKEFLAGS) doxygen)

help:
	@echo ""
	@echo "  Targets:"
	@echo ""
	@echo "    doxygen -- Build doxygen documentation (in docs directory)"
	@echo ""
	@echo "    *automake*          -- Standard automake targets"
	@echo ""

##
## Maintainer related targets
##

site: all
	(cd site && $(MAKE) $(AM_MAKEFLAGS) site)

URL_BU = "http://github.com/salvestrini/build-utils/raw/master/maint"

EXTERNAL =                                      \
        $(URL_BU)/bootstrap

update-local: Makefile
	rm -r -f fetch-dir && \
	mkdir fetch-dir && \
	for i in $(EXTERNAL) ; do \
	        URL="$$i" ; \
	        NAME=`echo "$$i" | $(SED) -e 's,^.*/,,'` ; \
	        $(FETCH) $$URL?raw=true fetch-dir/$$NAME && \
	        mv fetch-dir/$$NAME $$NAME || { \
	                rm -f fetch-dir/$$NAME ; \
	                exit 1 ; \
	        } \
	done && \
	rm -r -f fetch-dir
	chmod a+x bootstrap || { exit 1 ; }

maintainer-check-parameters: Makefile $(bin_PROGRAMS) $(bin_SCRIPTS)
	for i in $(bin_PROGRAMS) $(bin_SCRIPTS) ; do \
	        echo @ECHO_N@ "Checking standard parameters for $$i... " ; \
	        if ( ./$$i -h 2>&1 > /dev/null ) ; then \
	                echo "@ECHO_T@ok" ; \
	        else \
	                echo "@ECHO_T@error" ; \
	                exit 1 ; \
	        fi ; \
	done

maintainer-check-whitespaces: Makefile $(bin_SCRIPTS)
	$(WHITESPACE_DETECT) $(bin_SCRIPTS)

maintainer-check-local: Makefile maintainer-check-whitespaces maintainer-check-parameters
