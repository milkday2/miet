#include <stdio.h>
int main(void) {
    int y = 5;
    asm("subl $3,%[Y]"::[Y]"r"(y):"memory");
    printf("%d\n",y);
  return 0;
}
