#include "t1.h"
#include <cstdio>
#define PRINT_RESULT(var, varname, default)                                    \
  printf("%5s", varname ":");                                                 \
  print32(&var);                                                               \
  printf("%5s", varname "++:");                                               \
  incr32(&var);                                                                \
  print32(&var);                                                               \
  var = default;                                                               \
  printf("%5s", varname "--:");                                               \
  decr32(&var);                                                                \
  print32(&var)

void incr32(void *p) {
  unsigned int *pint = reinterpret_cast<unsigned int *>(p);
  (*pint)++;
}
void decr32(void *p) {
  unsigned int *pint = reinterpret_cast<unsigned int *>(p);
  (*pint)--;
}

int main(void) {
  int m = 223;
  int n = -455;
  float a = 0.0f;
  float b = 1.0f;
  float c = 12345678.0f;
  float d = 123456789.0f;

  PRINT_RESULT(m, "m", 223);
  PRINT_RESULT(n, "n", -455);
  PRINT_RESULT(a, "a", 0.0f);
  PRINT_RESULT(b, "b", 1.0f);
  PRINT_RESULT(c, "c", 12345678.0f);
  PRINT_RESULT(d, "d", 123456789.0f);
  return 0;
}
