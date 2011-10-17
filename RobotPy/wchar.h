/**
 *  @file   OS_NS_wchar.h
 *
 *  $Id: OS_NS_wchar.h 91995 2010-09-24 12:45:24Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */

#ifndef ACE_OS_NS_WCHAR_H
# define ACE_OS_NS_WCHAR_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);

/* Emulated wcscat - Appends a string. */
wchar_t *wcscat (wchar_t *destination, const wchar_t *source);

/* Emulated wcschr - Finds a character in a string. */
wchar_t *wcschr (const wchar_t *string, wchar_t c);

/* Emulated wcscmp - Compares strings. */
int wcscmp (const wchar_t *string1, const wchar_t *string2);

/* Emulated wcscpy - Copies a string. */
wchar_t *wcscpy (wchar_t *destination, const wchar_t *source);

/* Emulated wcscspn. */
size_t wcscspn (const wchar_t *string, const wchar_t *reject);
#if 0
/* Emulated wcsicmp - Performs a case insensitive comparison of strings. */
int wcsicmp (const wchar_t *string1, const wchar_t *string2);
#endif
/* Emulated wcslen - Returns the length of a string. */
size_t wcslen (const wchar_t *string);

/* Emulated wcscat - Appends a string. */
wchar_t *wcsncat (wchar_t *destination, const wchar_t *source, size_t count);

/* Emulated wcsncmp - Compares two arrays. */
int wcsncmp (const wchar_t *string1, const wchar_t *string2, size_t len);

/* Emulated wcsncpy - Copies an array. */
wchar_t *wcsncpy (wchar_t *destination, const wchar_t *source, size_t len);
#if 0
/* Emulated wcsnicmp - Performs a case insensitive comparison of two
 * arrays
 */
int wcsnicmp (const wchar_t *string1, const wchar_t *string2, size_t len);
#endif
/* Emulated wcspbrk - Searches for characters in a string. */
wchar_t *wcspbrk (const wchar_t *string, const wchar_t *charset);

/* Emulated wcsrchr (wchar_t version) - Finds the last occurrence of a
 * character in a string.
 */
wchar_t *wcsrchr (wchar_t *string, wchar_t c);
#if 0
/* Emulated wcsrchr (const wchar_t version) - Finds the last occurrence of a
 * character in a string.
 */
const wchar_t *wcsrchr (const wchar_t *string, wint_t c);
#endif
/* Emulated wcsspn. */
size_t wcsspn (const wchar_t *string, const wchar_t *charset);

/* Emulated wcsstr - Performs a case insensitive comparison of two strings. */
wchar_t *wcsstr (const wchar_t *string, const wchar_t *charset);

size_t wcslen (const wchar_t *);

wchar_t *wcscpy (wchar_t *, const wchar_t *);

int wcscmp (const wchar_t *, const wchar_t *);

int wcsncmp (const wchar_t *, const wchar_t *, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* ACE_OS_NS_STDIO_H */
