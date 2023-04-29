#include "t1.h"
#include <cstdio>
#define _TASK3(number, operation, target_num, sign_type)                       \
  *(reinterpret_cast<sign_type short *>(&number))operation(sign_type short)(   \
      target_num)

int main(void) {
  short m = 223;
  short n = -455;

  short smleft = _TASK3(m, <<, 1, signed);
  short smright = _TASK3(m, >>, 1, signed);
  unsigned short umleft = _TASK3(m, <<, 1, unsigned);
  unsigned short umright = _TASK3(m, >>, 1, unsigned);
  short snleft = _TASK3(n, <<, 1, signed);
  short snright = _TASK3(n, >>, 1, signed);
  unsigned short unleft = _TASK3(n, <<, 1, unsigned);
  unsigned short unright = _TASK3(n, >>, 1, unsigned);
  short sm_and15 = _TASK3(m, &, 15, signed);
  short sn_and15 = _TASK3(n, &, 15, signed);
  short sm_and16 = _TASK3(m, &, -16, signed);
  short sn_and16 = _TASK3(n, &, -16, signed);

  printf("%14s", "m:");
  print16(&m);
  printf("%14s", "sm<<1:");
  print16(&smleft);
  printf("%14s", "um<<1:");
  print16(&umleft);
  printf("%14s", "sm>>1:");
  print16(&smright);
  printf("%14s", "um>>1:");
  print16(&umright);
  printf("%14s", "sm & 15:");
  print16(&sm_and15);
  printf("%14s", "sm & -16:");
  print16(&sm_and16);

  printf("%14s", "n:");
  print16(&n);
  printf("%14s", "sn<<1:");
  print16(&snleft);
  printf("%14s", "un<<1:");
  print16(&unleft);
  printf("%14s", "sn>>1:");
  print16(&snright);
  printf("%14s", "un>>1:");
  print16(&unright);
  printf("%14s", "sn & 15:");
  print16(&sn_and15);
  printf("%14s", "sn & -16:");
  print16(&sn_and16);
  return 0;
}
