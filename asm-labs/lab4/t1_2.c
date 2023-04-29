#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINTARR(arr, size, format)                                            \
  for (int i = 0; i < size - 1; i++)                                           \
    printf(format " ", arr[i]);                                                \
  printf(format, arr[size - 1])

int main(void) {
  int size = 6;
  int *arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
    arr[i] = 0x44332211;
  size_t k = 3;
  int x = 0xC0CAC01A;
  __asm__("movl %[X],(%[arr],%[K],4)"
          :
          : [arr] "r"(arr), [X] "r"(x), [K] "r"(k)
          : "memory");
  PRINTARR(arr, size, "%X");

  size_t j = 2;
  __asm__("inc %[J]\n"
          "movb $0xFF,-1(%[arr],%[J],4)"
          :
          : [arr]"r"(arr),[J]"r"(j) 
          : "memory");
  printf("\n");
  PRINTARR(arr, size, "%X");

  free(arr);

  return 0;
}
