#include "sorting.h"
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

bool validate_sort(int *arr, int len);
int *pseudo_randarray(int len);
void quicksort_len(int *arr, int len) { quicksort(arr, 0, len - 1); }
double sort_time(void (*sort)(int *, int), int len, int repeats);

int main(void) {
  printf("%f ms", sort_time(quicksort_len, 8500*2 , 100));
  return 0;
}

double sort_time(void (*sort)(int *, int), int len, int repeats) {
  auto t1 = high_resolution_clock::now();
  auto t2 = high_resolution_clock::now();
  double time_ms = 0;
  int *arr = pseudo_randarray(len);
  int *arrcp = new int[len];
  for (int i = 0; i < len; i++)
    arrcp[i] = arr[i];

  for (int i = 0; i < repeats; i++) {
    t1 = high_resolution_clock::now();
    sort(arr, len);
    t2 = high_resolution_clock::now();
    if (!validate_sort(arr, len)) {
      printf("aborted: failed to sort!\n");
      return -1;
    }
    time_ms += ((duration<double, std::milli>)(t2 - t1)).count();
    for (int i = 0; i < len; i++)
      arr[i] = arrcp[i];
  }
  delete[] arr;
  delete[] arrcp;
  return time_ms;
}

bool validate_sort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

int *pseudo_randarray(int len) {
  int *arr = new int[len];
  srand(time(0));
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % 10000;
  }
  return arr;
}
