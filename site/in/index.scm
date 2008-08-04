(h3 "DESCRIPTION")
(p "ELKlib is an embeddable library that provides C/C++ support oriented "
   "to kernel level development. ELKlib mimics GNU libc and the Standard "
   "Template Library.")
(br)
(p (i "The library is under heavy development and is not yet usable, from the "
      "user point of view."))

(h4 "Features")
(p "The library provides the following features:")
(ul
 (li (b "C Support") ": "
     "The usual functions and macros available from libc are available")
 (li (b "C++ Support") ": "
     "STL-like iterators, algorithms, vectors, lists and strings")
 (li (b "BFD support") " (through libiberty): "
     "C++ Symbols demangling")
 )

(h4 "Ports")
(p "The only available port is for the x86 architecture")

(h3 "USAGE")
(h4 "Installation")
(p "ELKlib uses the autoconf/automake facilities. The simplest way to install "
   "the package in your system is:")
(ul
 (li "`" (samp "cd") "' to the directory containing the package's source code "
     "and type `" (samp "./configure") "' to configure the package for your "
     "system. "
     "Running `" (samp "configure") "' might take a while. While running, "
     "it prints some messages telling which features it is checking for")
 (li "Type `" (samp "make") "' to compile the package")
 (li "Optionally, type `"(samp "make") " check' to run any self-tests that come "
     "with the package")
 (li "Type `" (samp "make install") "' to install the programs and any data "
     "files and documentation")
 )

(p "Use `" (samp "./configure --help") "' to get a brief help of all "
   "configuration tweaks available.")
(br)
(p "You can remove the program binaries and object files from the "
   "source code directory by typing `" (samp "make clean") "'. "
   "To also remove the files that `" (samp "configure") "' created (so you can "
   "compile the package for a different architecture), type `"
   (samp "make distclean") "'.")
(br)
(p "You can also type `" (samp "make uninstall") "' to remove the installed "
   "files.")
(br)
(p "Note that the `" (samp "--prefix") "' option allows installation using "
   "different paths than the default ones, this option enables sandbox "
   "installations.")

(h4 "Use")
(p "To easily detect the presence of elklib in a host system, the following "
   "scripts come handy:")
(ul
 (li (samp "elklib-config") ": "
     "It should be used to list the available ports in the host machine"
     (pre
      "Usage: elklib-config [OPTIONS]" (br)
      "" (br)
      "OPTIONS:" (br)
      "    [-h|--help]" (br)
      "    [--version]" (br)
      "    [--target-cpus]" (br)
      )
     (br)
     )
 (li (samp "elklib-config-<target-cpu>") ": "
     "It should be used to query a port for compilation or linking related "
     "flags"
     (pre
      "Usage: elklib-config-<target-cpu> [OPTIONS]" (br)
      "" (br)
      "OPTIONS:" (br)
      "    [-h|--help]" (br)
      "    [--version]" (br)
      "    [--static-libs]" (br)
      "    [--cppflags]" (br)
      "    [--cflags]" (br)
      "    [--cxxcppflags]" (br)
      "    [--cxxflags]" (br)
      "    [--ldflags]" (br)
      )
     )
 )

(h3 "COPYING")
(p "ELKlib is licensed under the "
   (a (@ (href "http://www.gnu.org/licenses/licenses.html"))
      "GNU General Public License, version 2"))

(h3 "MAINTAINERS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>")

(h3 "AUTHORS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>")

(h3 "RELEASES")
(p "Sorry, no public release available at the moment.")

(h3 "MAILING LISTS")
(p "ELKlib has a single moderated mailing list, with an archive. "
   "In order to post a message to the mailing list you must be subscribed. "
   "Please consult the "
   (a (@ (href "http://lists.nongnu.org/mailman/listinfo/elklib-generic"))
      "ELKlib mailing list page")
   " for more information on subscribing to the mailing list.")

(h3 "REPORT A BUG")
(p "If you think you have found a bug in ELKlib then please send as complete "
   "a report as possible to <elklib AT nongnu.org>. An easy way to collect all "
   "the required information, such as platform and compiler, is to include "
   "in your report the config.log file available at the end of the "
   "configuration procedure. ")
(br)
(p "If you have a patch for a bug in Hybrid that hasn't yet been fixed in the "
   "latest repository sources, please be so kind to create it using the "
   "repository sources, not the release sources.")

(h3 "DEVELOPMENT")
(h4 "Browsing sources")
(p "You can browse the "
   (a (@ (href "http://git.savannah.nongnu.org/gitweb/?p=elklib.git"))
      "Git repository")
   " of this project with your web browser. This gives you a good "
   "picture of the current status of the source files. You may also view "
   "the complete histories of any file in the repository as well as "
   "differences among two versions.")

(h4 "Getting a copy of the Git Repository")
(p "Anonymous checkout:")
(br)
(samp (a (@ (href "http://savannah.gnu.org/maintenance/UsingGit")) git)
   " clone git://git.savannah.nongnu.org/elklib.git")

(h4 "Contribute")
(p "If you have time and programming skills, you can help us by developing "
   "missing features, regression tests or bug-fixing the present codebase. "
   "Subscribe to the "
   (a (@ (href "http://lists.nongnu.org/mailman/listinfo/elklib-generic"))
      "mailing list")
   ", drop us a mail and start coding. Send your code to the "
   "mailing list under the form of patches for the current revision system.")
(br)
(p "If you have time but no programming skills, you can help with "
   "documentation,  packaging, tests before releases etc ...")
