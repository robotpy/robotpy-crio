/* The following wcs* methods were created based on BSD code: */
/*-
 * Copyright (c) 1991, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * James W. Williams of NASA Goddard Space Flight Center.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "wchar.h"
#include <ctype.h>
#include <string.h>
#include <errno.h>


size_t
mbstowcs(wchar_t *pwcs, const char *s, size_t n)
{
        size_t cnt;
        wchar_t r;

        if (s == NULL) {
                errno = EINVAL;
                return (-1);
        }

        if (pwcs == NULL) {
                /* Convert and count only, do not store. */
                cnt = 0;
                while ((r = (wchar_t)(*s)) != 0) {
                        s++;
                        cnt++;
                }
                return (cnt);
        }

        /* Convert, store and count characters. */
        cnt = 0;
        while (n-- > 0) {
                *pwcs = (wchar_t)(*s);
                if (*pwcs++ == L'\0')
                        break;
                s++;
                ++cnt;
        }

        return (cnt);
}

size_t
wcstombs(char *s, const wchar_t *pwcs, size_t n)
{
        size_t cnt;
	int nb;

        if (pwcs == NULL) {
                errno = EINVAL;
                return (-1);
        }

        cnt = 0;

        if (s == NULL) {
                /* Convert and count only, do not store. */
                while (*pwcs != L'\0') {
                        if ((char)(*pwcs++) == 0) {
                                errno = EILSEQ;
                                return (-1);
                        }
                        cnt++;
                }
                return (cnt);
        }

        /* Convert, store and count characters. */
        nb = n;
        while (nb > 0) {
                if (*pwcs == L'\0') {
                        *s = '\0';
                        break;
                }
                if ((*s = (char)(*pwcs++)) == 0) {
                        errno = EILSEQ;
                        return (-1);
                }
                cnt++;
                nb--;
                s++;
        }

        return (cnt);
}

size_t
wcslen (const wchar_t *s)
{
  size_t len = 0;

  while (*s++ != 0)
    len++;

  return len;
}

wchar_t *
wcscpy (wchar_t *dest, const wchar_t *src)
{
  wchar_t *original_dest = dest;

  while ((*dest++ = *src++) != 0)
    continue;

  return original_dest;
}

int
wcscmp (const wchar_t *s, const wchar_t *t)
{
  const wchar_t *scan1 = s;
  const wchar_t *scan2 = t;

  while (*scan1 != 0 && *scan1 == *scan2)
    {
      ++scan1;
      ++scan2;
    }

  return *scan1 - *scan2;
}

int
wcsncmp (const wchar_t *s, const wchar_t *t, size_t len)
{
  const wchar_t *scan1 = s;
  const wchar_t *scan2 = t;

  while (len != 0 && *scan1 != 0 && *scan1 == *scan2)
    {
      ++scan1;
      ++scan2;
      --len;
    }

  return len == 0 ? 0 : *scan1 - *scan2;
}

wchar_t *
wcscat (wchar_t *destination, const wchar_t *source)
{
  wchar_t *save = destination;

  for (; *destination; ++destination);
  while ((*destination++ = *source++));
  return save;
}

wchar_t *
wcschr (const wchar_t *string, wchar_t c)
{
  for (;*string ; ++string)
    if (*string == c)
      return (wchar_t *) (string);

  return 0;
}

size_t
wcscspn (const wchar_t *s, const wchar_t *reject)
{
  const wchar_t *scan = 0;
  const wchar_t *rej_scan = 0;
  int count = 0;

  for (scan = s; *scan; scan++)
    {

      for (rej_scan = reject; *rej_scan; rej_scan++)
        if (*scan == *rej_scan)
          return count;

      count++;
    }

  return count;
}
#if 0
int
wcsicmp (const wchar_t *s, const wchar_t *t)
{
  const wchar_t *scan1 = s;
  const wchar_t *scan2 = t;

  while (*scan1 != 0
         && ACE_OS::ace_towlower (*scan1)
            == ACE_OS::ace_towlower (*scan2))
    {
      ++scan1;
      ++scan2;
    }

  // The following case analysis is necessary so that characters which
  // look negative collate low against normal characters but high
  // against the end-of-string NUL.

  if (*scan1 == '\0' && *scan2 == '\0')
    return 0;
  else if (*scan1 == '\0')
    return -1;
  else if (*scan2 == '\0')
    return 1;
  else
    return ACE_OS::ace_tolower (*scan1) - ACE_OS::ace_towlower (*scan2);
}
#endif

wchar_t *
wcsncat (wchar_t *destination, const wchar_t *source, size_t count)
{
  if (count != 0)
    {
      wchar_t *d = destination;
      const wchar_t *s = source;

      while (*d != 0)
        ++d;

      do
        {
          if ((*d = *s++) == 0)
            break;

          ++d;
        } while (--count != 0);

      *d = 0;
    }

  return destination;
}

wchar_t *
wcsncpy (wchar_t *destination, const wchar_t *source, size_t len)
{
  if (len != 0)
    {
      wchar_t *d = destination;
      const wchar_t *s = source;

      do
        {
          if ((*d++ = *s++) == 0)
            {
              /* NUL pad the remaining n-1 bytes */
              while (--len != 0)
                *d++ = 0;
              break;
            }
        } while (--len != 0);
    }

  return destination;
}
#if 0
int
wcsnicmp (const wchar_t *s, const wchar_t *t, size_t len)
{
  const wchar_t *scan1 = s;
  const wchar_t *scan2 = t;
  size_t count = 0;

  while (count++ < len
         && *scan1 != 0
         && ACE_OS::ace_towlower (*scan1)
            == ACE_OS::ace_towlower (*scan2))
    {
      ++scan1;
      ++scan2;
    }

  if (count > len)
    return 0;

  // The following case analysis is necessary so that characters which
  // look negative collate low against normal characters but high
  // against the end-of-string NUL.

  if (*scan1 == '\0' && *scan2 == '\0')
    return 0;
  else if (*scan1 == '\0')
    return -1;
  else if (*scan2 == '\0')
    return 1;
  else
    return ACE_OS::ace_towlower (*scan1) - ACE_OS::ace_towlower (*scan2);
}
#endif
wchar_t *
wcspbrk (const wchar_t *string, const wchar_t *charset)
{
  const wchar_t *scanp = 0;
  int c, sc;

  while ((c = *string++) != 0)
    {
      for (scanp = charset; (sc = *scanp++) != 0;)
        if (sc == c)
          return (wchar_t *) (string - 1);
    }

  return 0;
}
#if 0
const wchar_t *
wcsrchr (const wchar_t *s, wint_t c)
{
  const wchar_t *p = s + wcslen (s);

  while (*p != (wchar_t)(c))
    if (p == s)
      return 0;
    else
      p--;

  return p;
}
#endif
wchar_t *
wcsrchr (wchar_t *s, wchar_t c)
{
  wchar_t *p = s + wcslen (s);

  while (*p != c)
    if (p == s)
      return 0;
    else
      p--;

  return p;
}

size_t
wcsspn (const wchar_t *string, const wchar_t *charset)
{
  const wchar_t *p = string;
  const wchar_t *spanp = 0;
  wchar_t c, sc;

  /* Skip any characters in charset, excluding the terminating \0. */
cont:
  c = *p++;
  for (spanp = charset; (sc = *spanp++) != 0;)
    if (sc == c)
      goto cont;
  return (p - 1 - string);
}

wchar_t *
wcsstr (const wchar_t *string, const wchar_t *charset)
{
  wchar_t c, sc;
  size_t len;

  if ((c = *charset++) != 0)
    {
      len = wcslen (charset);
      do
        {
          do
            {
              if ((sc = *string++) == 0)
                return 0;
            } while (sc != c);
        } while (wcsncmp (string, charset, len) != 0);
      string--;
    }

  return (wchar_t *)(string);
}
