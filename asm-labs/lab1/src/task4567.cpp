#include <cstddef>
#include <cstdio>

template <typename T> T *makeArray(T number, size_t size) {
  T *array = new T[size];
  for (int i = 0; i < size; i++) {
    array[i] = number;
  }
  return array;
}

template <typename T>
void printfArray(T *array, size_t size, const char *format) {
  for (int i = 0; i < size; i++)
    printf(format, array[i]);
  printf("\n");
}

void check_scanf(int scanf_return, unsigned int input_num);

int main(void) {
  size_t arr_size = 5;
  signed char x8 = 0xED;
  short x16 = 0xDEAD;
  int x32 = 0xC0CAC01A;
  long long x64 = 0xC0FFEE11BEA7;
  float fx32 = (double)(-10) / (double)3;
  double fx64 = (double)(-10) / (double)3;

  signed char *Mb = makeArray<signed char>(x8, arr_size);
  short *Ms = makeArray<short>(x16, arr_size);
  int *Ml = makeArray<int>(x32, arr_size);
  long long *Mq = makeArray<long long>(x64, arr_size);
  float *Mfs = makeArray<float>(fx32, arr_size);
  double *Mfl = makeArray<double>(fx64, arr_size);

  printfArray<signed char>(Mb, arr_size, "%hhd\t");
  printfArray<signed char>(Mb, arr_size, "%02hhX\t");
  printfArray<short>(Ms, arr_size, "%hd\t");
  printfArray<short>(Ms, arr_size, "%04hX\t");
  printfArray<int>(Ml, arr_size, "%d\t");
  printfArray<int>(Ml, arr_size, "%08X\t");
  printfArray<long long>(Mq, arr_size, "%lld\t");
  printfArray<long long>(Mq, arr_size, "%016llX\t");
  printfArray<float>(Mfs, arr_size,
                     "%.2f\t"); // printf promotes floats to doubles
  printfArray<float>(Mfs, arr_size, "%e\t");
  printfArray<double>(Mfl, arr_size, "%.2f\t");
  printfArray<double>(Mfl, arr_size, "%e\t");

  puts("Input new 2nd elemets");
  printf("signed i8:");
  check_scanf(scanf("%hhd", Mb + 2), 1);
  printfArray<signed char>(Mb, arr_size, "%hhd\t");

  printf("signed i16:");
  check_scanf(scanf("%hd", Ms + 2), 1);
  printfArray<short>(Ms, arr_size, "%hd\t");

  printf("signed i32:");
  check_scanf(scanf("%d", Ml + 2), 1);
  printfArray<int>(Ml, arr_size, "%d\t");

  printf("signed i64:");
  check_scanf(scanf("%lld", Mq + 2), 1);
  printfArray<long long>(Mq, arr_size, "%lld\t");

  printf("f32:");
  check_scanf(scanf("%f", Mfs + 2), 1);
  printfArray<float>(Mfs, arr_size, "%.3f\t");

  printf("f64:");
  check_scanf(scanf("%lf", Mfl + 2), 1);
  printfArray<double>(Mfl, arr_size, "%.3f\t");

  printf("Input 5 new f64 elements for Mfl:\n");
  check_scanf(
      scanf("%lf %lf %lf %lf %lf", Mfl, Mfl + 1, Mfl + 2, Mfl + 3, Mfl + 4), 5);
  printfArray<double>(Mfl, arr_size, "%.3f\t");

  delete[] Mb;
  delete[] Ms;
  delete[] Ml;
  delete[] Mq;
  delete[] Mfs;
  delete[] Mfl;
  return 0;
}

void check_scanf(int scanf_return, unsigned int input_num) {
  if (scanf_return < input_num)
    printf("Error: read %d out of %u expected inputs!\n", scanf_return,
           input_num);
  int c;
  while ((c = fgetc(stdin)) != EOF && c != '\n')
    ;
}
