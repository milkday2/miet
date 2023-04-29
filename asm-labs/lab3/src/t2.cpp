#include "t1.h"
#include <cstdio>

#define _16TO32(i16,sign_type) \
   static_cast<sign_type int>(*reinterpret_cast<sign_type short*>(&i16)) 

int main(void) {
  short m = 223;
  short n = -455;

  int sm32 = _16TO32(m, signed);
  unsigned int um32 = _16TO32(m, unsigned);
  int sn32 = _16TO32(n, signed);
  unsigned int un32 = _16TO32(n, unsigned);
  printf("m, sm32, um32:\n");
  print16(&m);
  print32(&sm32);
  print32(&um32);
  printf("n, sn32, un32:\n");
  print16(&n);
  print32(&sn32);
  print32(&un32);
  return 0;
}

