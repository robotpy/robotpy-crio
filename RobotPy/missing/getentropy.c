
#include "Python.h"
#include <random.h>

int getentropy(void * buf, size_t buflen) {
  read_random(buf, buflen);
  return 0;
}