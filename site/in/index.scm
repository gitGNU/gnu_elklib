(h2 "DESCRIPTION")
(p "ELKlib is an embeddable library that provides C/C++ support oriented "
   "to kernel level development. ELKlib mimics GNU libc and the Standard "
   "Template Library.")

(h3 "Features")
(p "The library provides the following features:")
(ul
 (li (b "C Support") ": "
     "The usual functions and macros available from libc are available")
 (li (b "C++ Support") ": "
     "STL-like iterators, algorithms, vectors, lists and strings")
 (li (b "BFD support") " (through libiberty): "
     "C++ Symbols demangling"))

(h3 "Ports")
(p "The only available port is for the x86 architecture")

(h3 "Testimonials")
(p "ELKlib is used in the "
   (a (@ (href "http://www.nongnu.org/hybrid")) "Hybrid")
   " kernel.")

(h2 "USAGE")

(h3 "Prerequisites")
(p "In order to install ELKlib into your system you will need a relatively "
   "recent C/C++ compiler.")

(h3 "Installation")
(p "ELKlib uses the autotools facilities. The simplest way to install "
   "the package in your system is:")
(ul
 (li (kbd "cd") " to the directory containing the package's source code "
     "and type " (kbd "./configure") " to configure the package for your "
     "system."
     "Running " (kbd "configure") " might take a while. While running, "
     "it prints some messages telling which features it is checking for")
 (li "Type " (kbd "make") " to compile the package")
 (li "Optionally, type " (kbd "make check") " to run all self-tests that "
     "come with the package")
 (li "Type " (kbd "make install") " to install the programs and any data "
     "files and documentation"))

(p "Use " (kbd "./configure --help") " to get a brief help of all "
   "configuration tweaks available.")
(p "You can remove the program binaries and object files from the "
   "source code directory by typing " (kbd "make clean") ". "
   "To also remove the files that " (samp "configure") " created (so you "
   "can compile the package for a different architecture), type "
   (kbd "make distclean") ".")
(p "You can also type " (kbd "make uninstall") " to remove the installed "
   "files.")
(p "Note that the " (samp "--prefix") " option allows installation using "
   "different paths than the default ones, this option enables sandbox "
   "installations.")

(h3 "Use")
(p "To easily detect the presence of elklib in a host system, the following "
   "scripts come handy:")

(h5 "elklib-config")
(p "The script should be used to list the available ports "
   "installed in the host machine")
(pre (@ class "terminal")
"
Usage: elklib-config [OPTIONS]

OPTIONS:
    [-h|--help]
    [--version]
    [--target-cpus]
")

(h5 "elklib-config-<target-cpu>")
(p "The script should be used to query a port for compilation or linking "
   "related flags")
(pre (@ class "terminal")
"
Usage: elklib-config-<target-cpu> [OPTIONS]

OPTIONS:
    [-h|--help]
    [--version]
    [--static-libs]
    [--cppflags]
    [--cflags]
    [--cxxcppflags]
    [--cxxflags]
    [--ldflags]
")

(h2 "COPYING")
(p "The project is licensed under the "
   (a (@ (href "http://www.gnu.org/licenses/licenses.html"))
      "GNU General Public License, version 2"))

(h2 "MAINTAINERS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>")

(h2 "AUTHORS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>")

(h2 "RELEASES")
(p "Sorry, no public release available at the moment.")

(h2 "MAILING LISTS")
(p "The project has a single moderated mailing list, with an archive. "
   "In order to post a message to the mailing list you must be subscribed. "
   "Please consult the "
   (a (@ (href "http://lists.nongnu.org/mailman/listinfo/elklib-generic"))
      "mailing list page")
   " for more information on subscribing to the mailing list.")

(h2 "REPORT A BUG")
(p "If you think you have found a bug then please send as complete a report "
   "as possible to "
   "<elklib-generic AT nongnu DOT org>. "
   "An easy way to collect all the required information, such as platform and "
   "compiler, is to include in your report the config.log file available at "
   "the end of the configuration procedure.")
(p "If you have a patch for a bug that hasn't yet been fixed in the "
   "latest repository sources, please be so kind to create it using the "
   "repository sources, not the release sources.")

(h2 "DEVELOPMENT")

(h3 "Browsing sources")
(p "You can browse the "
   (a (@ (href "http://git.savannah.nongnu.org/gitweb/?p=elklib.git"))
      "Git repository")
   " of this project with your web browser. This gives you a good "
   "picture of the current status of the source files. You may also view "
   "the complete histories of any file in the repository as well as "
   "differences among two versions.")

(h3 "Getting a copy of the Git Repository")
(p "Anonymous checkout:")
(pre (@ class "terminal")
     (a (@ (href "http://savannah.gnu.org/maintenance/UsingGit")) "git")
     " clone git://git.savannah.nongnu.org/elklib.git")

(h3 "Contribute")
(p "If you have time and programming skills, you can help us by developing "
   "missing features, regression tests or bug-fixing the present codebase. "
   "Subscribe to the "
   (a (@ (href "http://lists.nongnu.org/mailman/listinfo/elklib-generic"))
      "mailing list")
   ", drop us a mail and start coding. Send your code to the "
   "mailing list under the form of patches for the current revision system.")
(p "If you have time but no programming skills, you can help with "
   "documentation,  packaging, tests before releases etc ...")
