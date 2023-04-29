#include <cstddef>
#include <cstdio>

void printDump(void *, size_t);

int main(void) {
  int x = 0x99887766;
  printf("0x99887766: ");
  printDump(&x, sizeof(int));

  int y = 5;
  int z = -5;
  int arr[] = {x, y, z};
  printf("\n[0x99887766,5,-5]: ");
  printDump(arr, 3 * sizeof(int));

  double yf = 5.0;
  printf("\ndouble 5.0: ");
  printDump(&yf, sizeof(double));
  printf("\n");

  char jzyx[] = "jzyx";
  char rus[] = "ёяюэ";
  printf("\nchar string jzyx: ");
  printDump(jzyx, 5 * sizeof(char));
  printf("\nchar string ёяюэ: ");
  printDump(rus, 5 * sizeof(char));

  wchar_t Ljzyx[] = L"jzyx";
  wchar_t Lrus[] = L"ёяюэ";
  printf("\nwchar_t string jzyx: ");
  printDump(Ljzyx, 5 * sizeof(wchar_t));
  printf("\nwchar_t string ёяюэ: ");
  printDump(Lrus, 5 * sizeof(wchar_t));
  return 0;
}

void printDump(void *p, size_t N) {
  unsigned char *p8 = reinterpret_cast<unsigned char *>(p);
  for (int i = 0; i < N; i++) {
    printf("%02hhX ", *(p8 + i));
  }
}
