/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Maintained by hand. */

/* Define NO_MULTIBYTE_SUPPORT to not compile in support for multibyte
   characters, even if the OS supports them. */
#undef NO_MULTIBYTE_SUPPORT

#undef _FILE_OFFSET_BITS

/* Define if on MINIX.  */
#undef _MINIX

/* Define as the return type of signal handlers (int or void).  */
#undef RETSIGTYPE

#undef VOID_SIGHANDLER

/* Characteristics of the compiler. */
#undef sig_atomic_t

#undef size_t

#undef ssize_t

#undef const

#undef volatile

#undef PROTOTYPES

#undef __CHAR_UNSIGNED__

/* Define if the `S_IS*' macros in <sys/stat.h> do not work properly.  */
#undef STAT_MACROS_BROKEN

/* Define if you have the fcntl function. */
#undef HAVE_FCNTL

/* Define if you have the getpwent function. */
#undef HAVE_GETPWENT

/* Define if you have the getpwnam function. */
#undef HAVE_GETPWNAM

/* Define if you have the getpwuid function. */
#undef HAVE_GETPWUID

/* Define if you have the isascii function. */
#undef HAVE_ISASCII

/* Define if you have the iswctype function.  */
#undef HAVE_ISWCTYPE

/* Define if you have the iswlower function.  */
#undef HAVE_ISWLOWER

/* Define if you have the iswupper function.  */
#undef HAVE_ISWUPPER

/* Define if you have the isxdigit function. */
#undef HAVE_ISXDIGIT

/* Define if you have the kill function. */
#undef HAVE_KILL

/* Define if you have the lstat function. */
#undef HAVE_LSTAT

/* Define if you have the mbrlen function. */
#undef HAVE_MBRLEN

/* Define if you have the mbrtowc function. */
#undef HAVE_MBRTOWC

/* Define if you have the mbsrtowcs function. */
#undef HAVE_MBSRTOWCS

/* Define if you have the memmove function. */
#undef HAVE_MEMMOVE

/* Define if you have the putenv function.  */
#undef HAVE_PUTENV

/* Define if you have the select function.  */
#undef HAVE_SELECT

/* Define if you have the setenv function.  */
#undef HAVE_SETENV

/* Define if you have the setlocale function. */
#undef HAVE_SETLOCALE

/* Define if you have the strcasecmp function.  */
#undef HAVE_STRCASECMP

/* Define if you have the strcoll function.  */
#undef HAVE_STRCOLL

#undef STRCOLL_BROKEN

/* Define if you have the strpbrk function.  */
#undef HAVE_STRPBRK

/* Define if you have the tcgetattr function.  */
#undef HAVE_TCGETATTR

/* Define if you have the towlower function.  */
#undef HAVE_TOWLOWER

/* Define if you have the towupper function.  */
#undef HAVE_TOWUPPER

/* Define if you have the vsnprintf function.  */
#undef HAVE_VSNPRINTF

/* Define if you have the wcrtomb function.  */
#define HAVE_WCRTOMB 1

/* Define if you have the wcscoll function.  */
#undef HAVE_WCSCOLL

/* Define if you have the wctype function.  */
#undef HAVE_WCTYPE

/* Define if you have the wcwidth function.  */
#undef HAVE_WCWIDTH

#undef STDC_HEADERS

/* Define if you have the <dirent.h> header file.  */
#undef HAVE_DIRENT_H

/* Define if you have the <fcntl.h> header file.  */
#undef HAVE_FCNTL_H

/* Define if you have the <langinfo.h> header file.  */
#undef HAVE_LANGINFO_H

/* Define if you have the <limits.h> header file.  */
#undef HAVE_LIMITS_H

/* Define if you have the <locale.h> header file.  */
#undef HAVE_LOCALE_H

/* Define if you have the <memory.h> header file.  */
#undef HAVE_MEMORY_H

/* Define if you have the <ndir.h> header file.  */
#undef HAVE_NDIR_H

/* Define if you have the <pwd.h> header file.  */
#undef HAVE_PWD_H

/* Define if you have the <stdarg.h> header file.  */
#undef HAVE_STDARG_H

/* Define if you have the <stdlib.h> header file.  */
#undef HAVE_STDLIB_H

/* Define if you have the <string.h> header file.  */
#undef HAVE_STRING_H

/* Define if you have the <strings.h> header file.  */
#undef HAVE_STRINGS_H

/* Define if you have the <sys/dir.h> header file.  */
#undef HAVE_SYS_DIR_H

/* Define if you have the <sys/file.h> header file.  */
#undef HAVE_SYS_FILE_H

/* Define if you have the <sys/ndir.h> header file.  */
#undef HAVE_SYS_NDIR_H

/* Define if you have the <sys/pte.h> header file.  */
#undef HAVE_SYS_PTE_H

/* Define if you have the <sys/ptem.h> header file.  */
#undef HAVE_SYS_PTEM_H

/* Define if you have the <sys/select.h> header file.  */
#undef HAVE_SYS_SELECT_H

/* Define if you have the <sys/stream.h> header file.  */
#undef HAVE_SYS_STREAM_H

/* Define if you have the <termcap.h> header file.  */
#undef HAVE_TERMCAP_H

/* Define if you have the <termio.h> header file.  */
#undef HAVE_TERMIO_H

/* Define if you have the <termios.h> header file.  */
#undef HAVE_TERMIOS_H

/* Define if you have the <unistd.h> header file.  */
#undef HAVE_UNISTD_H

/* Define if you have the <varargs.h> header file.  */
#undef HAVE_VARARGS_H

/* Define if you have the <wchar.h> header file.  */
#undef HAVE_WCHAR_H

/* Define if you have the <wctype.h> header file.  */
#undef HAVE_WCTYPE_H

#undef HAVE_MBSTATE_T

/* Define if you have wchar_t in <wctype.h>. */
/* #undef HAVE_WCHAR_T */

/* Define if you have wctype_t in <wctype.h>. */
#undef HAVE_WCTYPE_T

/* Define if you have wint_t in <wctype.h>. */  
/* #undef HAVE_WINT_T */

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
#undef HAVE_LANGINFO_CODESET

/* Definitions pulled in from aclocal.m4. */
#undef VOID_SIGHANDLER

#undef GWINSZ_IN_SYS_IOCTL

#undef STRUCT_WINSIZE_IN_SYS_IOCTL

#undef STRUCT_WINSIZE_IN_TERMIOS

#undef TIOCSTAT_IN_SYS_IOCTL

#undef FIONREAD_IN_SYS_IOCTL

#undef SPEED_T_IN_SYS_TYPES

#undef HAVE_GETPW_DECLS

#undef STRUCT_DIRENT_HAS_D_INO

#undef STRUCT_DIRENT_HAS_D_FILENO

#undef HAVE_BSD_SIGNALS

#undef HAVE_POSIX_SIGNALS

#undef HAVE_USG_SIGHOLD

#undef MUST_REINSTALL_SIGHANDLERS

#undef HAVE_POSIX_SIGSETJMP

#undef CTYPE_NON_ASCII

#define PACKAGE_NAME "readline"
#define PACKAGE_TARNAME "readline"
#define PACKAGE_VERSION "6.1"
#define PACKAGE_STRING "readline 6.1"
#define PACKAGE_BUGREPORT "bug-readline@gnu.org"
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_UNISTD_H 1
#define __EXTENSIONS__ 1
#define _ALL_SOURCE 1
#define _GNU_SOURCE 1
#define _POSIX_PTHREAD_SEMANTICS 1
#define _TANDEM_SOURCE 1
#define PROTOTYPES 1
#define __PROTOTYPES 1
#define RETSIGTYPE void
#define STDC_HEADERS 1
#define HAVE_DIRENT_H 1
#define HAVE_FCNTL 1
#define HAVE_KILL 1
#define HAVE_MEMMOVE 1
#define HAVE_PUTENV 1
#define HAVE_SELECT 1
#define HAVE_SETLOCALE 1
#define HAVE_STRCASECMP 1
#define HAVE_STRPBRK 1
#define HAVE_TCGETATTR 1
#define HAVE_VSNPRINTF 1
#define HAVE_ISASCII 1
#define HAVE_ISXDIGIT 1
#define HAVE_FCNTL_H 1
#define HAVE_UNISTD_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STDARG_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_LIMITS_H 1
#define HAVE_LOCALE_H 1
#define HAVE_POSIX_SIGNALS 1
#define VOID_SIGHANDLER 1
#define HAVE_STRUCT_DIRENT_D_INO 1
#define HAVE_MBRLEN 1
#define HAVE_MBSCMP 1
#define HAVE_MBSCMP 1
#define HAVE_MBSRTOWCS 1
#define HAVE_MBSCHR 1
#define HAVE_WCRTOMB 1
#define HAVE_WCSCOLL 1
#define HAVE_WCSDUP 1
#define HAVE_WCWIDTH 1
#define HAVE_WCTYPE 1
#define HAVE_ISWLOWER 1
#define HAVE_ISWUPPER 1
#define HAVE_TOWLOWER 1
#define HAVE_TOWUPPER 1
#define HAVE_ISWCTYPE 1

/* modify settings or make new ones based on what autoconf tells us. */

/* Ultrix botches type-ahead when switching from canonical to
   non-canonical mode, at least through version 4.3 */
#if !defined (HAVE_TERMIOS_H) || !defined (HAVE_TCGETATTR) || defined (ultrix)
#  define TERMIOS_MISSING
#endif

#if defined (__STDC__) && defined (HAVE_STDARG_H)
#  define PREFER_STDARG
#  define USE_VARARGS
#else
#  if defined (HAVE_VARARGS_H)
#    define PREFER_VARARGS
#    define USE_VARARGS
#  endif
#endif
