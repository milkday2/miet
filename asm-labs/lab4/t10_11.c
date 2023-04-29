#include <stdio.h>

int main(void) {
  double x;
  scanf("%lf", &x);
  double y = 3.0;
  char z;
  __asm__("vcomisd %[Y],%[X]\n"
          "setne %[Z]\n"
          : [Z] "=r"(z)
          : [X] "x"(x), [Y] "x"(y)
          :);
  printf("%hhd\n", z);

    long int tmp;
  __asm__(
          "vcmpsd $0x04,%[Y],%[X],%[X]\n"
          "movq %[X],%[tmp]\n"
          "movb $1, %b[Z]\n"
          "and %b[tmp],%b[Z]\n"
          :[Z]"=r"(z),[tmp]"=&r"(tmp)
          :[X]"x"(x),[Y]"x"(y)
          :);
  printf("%hhd\n",z);

  __asm__("fucomip %[Y],%[X]\n"
          "setne %[Z]\n"
          "fstp %%st(0)\n"
          :[Z]"=r"(z)
          :[X]"t"(x),[Y]"f"(y)
          :
         );
  printf("%hhd\n",z);
  return 0;
}
