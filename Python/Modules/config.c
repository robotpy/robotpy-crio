/* -*- C -*- ***********************************************
Copyright (c) 2000, BeOpen.com.
Copyright (c) 1995-2000, Corporation for National Research Initiatives.
Copyright (c) 1990-1995, Stichting Mathematisch Centrum.
All rights reserved.

See the file "Misc/COPYRIGHT" for information on usage and
redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
******************************************************************/

/* Module configuration */

/* !!! !!! !!! This file is edited by the makesetup script !!! !!! !!! */

/* This file contains the table of built-in modules.
   See init_builtin() in import.c. */

#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif


extern PyObject* PyInit__thread(void);
extern PyObject* PyInit_signal(void);
/*posix posixmodule.c*/
extern PyObject* PyInit_errno(void);
/*pwd pwdmodule.c*/
extern PyObject* PyInit__sre(void);
extern PyObject* PyInit__codecs(void);
extern PyObject* PyInit__weakref(void);
extern PyObject* PyInit__functools(void);
extern PyObject* PyInit__locale(void);
extern PyObject* PyInit__io(void);
extern PyObject* PyInit_zipimport(void);
extern PyObject* PyInit__symtable(void);
extern PyObject* PyInit_array(void);
extern PyObject* PyInit_cmath(void);
extern PyObject* PyInit_math(void);
extern PyObject* PyInit__struct(void);
extern PyObject* PyInit_time(void);
extern PyObject* PyInit_operator(void);
extern PyObject* PyInit__testcapi(void);
extern PyObject* PyInit__random(void);
extern PyObject* PyInit__collections(void);
extern PyObject* PyInit_itertools(void);
extern PyObject* PyInit_atexit(void);
extern PyObject* PyInit__elementtree(void);
extern PyObject* PyInit__pickle(void);
extern PyObject* PyInit_datetime(void);
extern PyObject* PyInit__bisect(void);
extern PyObject* PyInit__heapq(void);
extern PyObject* PyInit_unicodedata(void);
extern PyObject* PyInit_fcntl(void);
extern PyObject* PyInit_select(void);
extern PyObject* PyInit_mmap(void);
extern PyObject* PyInit__csv(void);
extern PyObject* PyInit__socket(void);
extern PyObject* PyInit__md5(void);
extern PyObject* PyInit__sha1(void);
extern PyObject* PyInit__sha256(void);
extern PyObject* PyInit__sha512(void);
extern PyObject* PyInit_binascii(void);
extern PyObject* PyInit_parser(void);
extern PyObject* PyInit_fpectl(void);
extern PyObject* PyInit_fpetest(void);
extern PyObject* PyInit_zlib(void);
extern PyObject* PyInit_pyexpat(void);

/* -- ADDMODULE MARKER 1 -- */

extern PyObject* PyMarshal_Init(void);
extern PyObject* PyInit_imp(void);
extern PyObject* PyInit_gc(void);
extern PyObject* PyInit__ast(void);
extern PyObject* _PyWarnings_Init(void);

struct _inittab _PyImport_Inittab[] = {

	{"_thread", PyInit__thread},
	{"signal", PyInit_signal},
/*posix posixmodule.c*/
	{"errno", PyInit_errno},
/*pwd pwdmodule.c*/
	{"_sre", PyInit__sre},
	{"_codecs", PyInit__codecs},
	{"_weakref", PyInit__weakref},
	{"_functools", PyInit__functools},
	{"_locale", PyInit__locale},
	{"_io", PyInit__io},
	{"zipimport", PyInit_zipimport},
	{"_symtable", PyInit__symtable},
	{"array", PyInit_array},
	{"cmath", PyInit_cmath},
	{"math", PyInit_math},
	{"_struct", PyInit__struct},
	{"time", PyInit_time},
	{"operator", PyInit_operator},
	{"_testcapi", PyInit__testcapi},
	{"_random", PyInit__random},
	{"_collections", PyInit__collections},
	{"itertools", PyInit_itertools}, 
	{"atexit", PyInit_atexit},
	{"_elementtree", PyInit__elementtree},
	{"_pickle", PyInit__pickle},
	{"datetime", PyInit_datetime},
	{"_bisect", PyInit__bisect},
	{"_heapq", PyInit__heapq},
	{"unicodedata", PyInit_unicodedata},
	{"fcntl", PyInit_fcntl},
	{"select", PyInit_select},
	{"mmap", PyInit_mmap},
	{"_csv", PyInit__csv},
	{"_socket", PyInit__socket},
	{"_md5", PyInit__md5},
	{"_sha1", PyInit__sha1},
	{"_sha256", PyInit__sha256},
	{"_sha512", PyInit__sha512},
	{"binascii", PyInit_binascii},
	{"parser", PyInit_parser},
	{"fpectl", PyInit_fpectl},
	{"fpetest", PyInit_fpetest},
	{"zlib", PyInit_zlib},
	{"pyexpat", PyInit_pyexpat},
/* -- ADDMODULE MARKER 2 -- */

	/* This module lives in marshal.c */
	{"marshal", PyMarshal_Init},

	/* This lives in import.c */
	{"imp", PyInit_imp},

	/* This lives in Python/Python-ast.c */
	{"_ast", PyInit__ast},

	/* These entries are here for sys.builtin_module_names */
	{"__main__", NULL},
	{"builtins", NULL},
	{"sys", NULL},

	/* This lives in gcmodule.c */
	{"gc", PyInit_gc},

	/* This lives in _warnings.c */
	{"_warnings", _PyWarnings_Init},

	/* Sentinel */
	{0, 0}
};


#ifdef __cplusplus
}
#endif
