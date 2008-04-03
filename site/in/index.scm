(h3 "DESCRIPTION")
(p
 "ELKlib is an embeddable library for kernel-level development.
 It should provide basic C/C++ support (string/memory functions,
 STL-like containers and so on) for kernel developers. A sort of
 uClibc/newlib oriented to kernel development."
 )

(h3 "MAINTAINERS")
(p
 "Francesco Salvestrini <salvestrini AT gmail DOT com>"
 )

(h3 "AUTHORS")
(p "Francesco Salvestrini <salvestrini AT gmail DOT com>"
 )

(h3 "RELEASES")
(p "Sorry, no public release available at the moment.")

(h3 "MAILING LISTS")
(p
 "ELKlib has several moderated mailing lists, each with an archive.
 For general ELKlib discussions, use <elklib-user AT nongnu.org>.
 Email bug reports to <elklib-bug AT nongnu.org>. For more information on
 submitting bugs, please see the section Report a Bug below.
 If you have a patch for a bug in ELKlib that hasn't yet been fixed in the
 latest repository sources, please send the patch (made for the git sources,
 not the release sources) to <elklib-patch AT nongnu.org>."
 )

(h3 "REPORT A BUG")
(p
 "If you think you have found a bug in ELKlib, then please send as complete
 a report as possible to <elklib-bug AT nongnu.org>. An easy way to collect all
 the required information, such as platform and compiler, is to run make check,
 and include the resulting file tests/testsuite.log to your report.
 Disagreements between the manual and the code are also bugs."
 )

(h3 "DEVELOPMENT")
(h4 "Browsing sources")
(p
 "You can Browse the "
 (a (@ (href "http://git.savannah.nongnu.org/gitweb/?p=elklib.git"))
    "Git repository")
 " of this project with your web browser. This gives you a good
 picture of the current status of the source files. You may also view
 the complete histories of any file in the repository as well as
 differences among two versions."
 )
(h4 "Getting a Copy of the Git Repository")
(p "Anonymous checkout:")
(br)
(p (a (@ (href "http://savannah.gnu.org/maintenance/UsingGit")) git)
   " clone git://git.savannah.nongnu.org/elklib.git")
