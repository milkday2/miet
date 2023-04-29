#include <stdio.h>

int main(void) {
  /*unsigned*/ int x;
  char z;
  scanf("%d", &x);
  __asm__("cmpl $-3,%[X]\n"
          "setne %[Z]\n"
          : [Z] "=r"(z)
          : [X] "r"(x)
          : "cc");
  printf("%hhd\n", z);

  return 0;
}
