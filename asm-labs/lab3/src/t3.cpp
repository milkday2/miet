#include "t1.h"
#include <cstdio>
#define _TASK3(number, operation, target_num, sign_type)                       \
  *(reinterpret_cast<sign_type short *>(                                       \
      &number))operation (sign_type short)(target_num)

int main(void) {
  short m = 223;
  short n = -455;

  short sm2 = _TASK3(m, *, 2, signed);
  unsigned short um2 = _TASK3(m, *, 2, unsigned);
  short sn2 = _TASK3(n, *, 2, signed);
  unsigned short un2 = _TASK3(n, *, 2, unsigned);
  short smhalf = _TASK3(m,/,2,signed);
  unsigned short umhalf = _TASK3(m,/,2,unsigned);
  short snhalf = _TASK3(n,/,2,signed);
  unsigned short unhalf = _TASK3(n,/,2,unsigned);

  unsigned short ummod16 = _TASK3(m,%,16,unsigned);
  unsigned short unmod16 = _TASK3(n,%,16,unsigned);

  unsigned short umrounded = _TASK3(m, &, 0xfff0, unsigned);
  unsigned short unrounded = _TASK3(n, &, 0xfff0, unsigned);

  printf("%14s","m:");
  print16(&m);
  printf("%14s","sm*2:");
  print16(&sm2);
  printf("%14s","um*2:");
  print16(&um2);
  printf("%14s","sm/2:");
  print16(&smhalf);
  printf("%14s","um/2:");
  print16(&umhalf);
  printf("%14s","um%16:");
  print16(&ummod16);
  printf("%14s","um rounded:");
  print16(&umrounded);

  printf("%14s","n:");
  print16(&n);
  printf("%14s","sn*2:");
  print16(&sn2);
  printf("%14s","un*2:");
  print16(&un2);
  printf("%14s","sn/2:");
  print16(&snhalf);
  printf("%14s","un/2:");
  print16(&unhalf);
  printf("%14s","un%16:");
  print16(&unmod16);
  printf("%14s","un rounded:");
  print16(&unrounded);
  return 0;
}
