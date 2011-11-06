
/* Support for dynamic loading of extension modules */

#include "Python.h"
#include "importdl.h"

#include <ioLib.h>
#include <loadLib.h>
#include <symLib.h>
#include <sysSymTbl.h>

const struct filedescr _PyImport_DynLoadFiletab[] = {
        {".pyd", "rb", C_EXTENSION},
        {"module.pyd", "rb", C_EXTENSION},
	{0, 0}
};

dl_funcptr _PyImport_GetDynLoadFunc(const char *fqname, const char *shortname,
				    const char *pathname, FILE *fp)
{
	dl_funcptr p;
	SYM_TYPE type;
        MODULE_ID handle;
	char funcname[258];
	char pathbuf[260];

	if (strchr(pathname, '/') == NULL) {
		/* Prefix bare filename with "./" */
		PyOS_snprintf(pathbuf, sizeof(pathbuf), "./%-.255s", pathname);
		pathname = pathbuf;
	}

	PyOS_snprintf(funcname, sizeof(funcname), "PyInit_%.200s", shortname);

	if (symFindByName(sysSymTbl, funcname, (char **)&p, &type) == OK)
		return p;

	if (Py_VerboseFlag)
		PySys_WriteStderr("loadModule(\"%s\");\n", pathname);

        if (fp != NULL) {
		handle = loadModule(fileno(fp), LOAD_GLOBAL_SYMBOLS);
        } else {
		int fd = open(pathname, O_RDONLY, 0644);
		handle = loadModule(fd, LOAD_GLOBAL_SYMBOLS);
		close(fd);
	}

	if (handle == NULL) {
		const char *error = strerror(errno);
		if (error == NULL)
			error = "unknown loadModule() error";
		PyErr_SetString(PyExc_ImportError, error);
		return NULL;
	}
	if (symFindByName(sysSymTbl, funcname, (char **)&p, &type) != OK)
	{
		const char *error = strerror(errno);
		if (error == NULL)
			error = "unknown symFindByName() error";
		PyErr_SetString(PyExc_ImportError, error);
		return NULL;
	}
	return p;
}
