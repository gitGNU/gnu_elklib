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
(p "The only available port at the moment is for the x86 architecture.")

(h3 "Testimonials")
(p "ELKlib is used in the "
   (a (@ (href "http://www.nongnu.org/hybrid")) "Hybrid")
   " kernel.")

(h2 "COPYING")
(p "The project is licensed under the "
   (a (@ (href "http://www.gnu.org/licenses/licenses.html"))
      "GNU General Public License, version 2"))

(h2 "MAINTAINERS")
(p "Francesco Salvestrini")

(h2 "AUTHORS")
(p "Francesco Salvestrini")

(h2 "MAILING LISTS")
(p "The project has a single moderated mailing list, with an archive. "
   "In order to post a message to the mailing list you must be subscribed. "
   "Please consult the "
   (a (@ (href "http://lists.nongnu.org/mailman/listinfo/elklib-generic"))
      "mailing list page")
   " for more information on subscribing to the mailing list.")

(h2 "REPORT A BUG")
(p "If you think you have found a bug then please send as complete a report "
   "as possible to <" ,PACKAGE_BUGREPORT ">. "
   "An easy way to collect all the required information, such as platform and "
   "compiler, is to include in your report the config.log file available at "
   "the end of the configuration procedure.")
(p "If you have a patch for a bug that hasn't yet been fixed in the "
   "latest repository sources, please be so kind to create it using the "
   "repository sources, not the release sources.")
