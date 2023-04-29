
#define swap(i1, i2, temp)                                                     \
  temp = i1;                                                                   \
  i1 = i2;                                                                     \
  i2 = temp

int hoare_partition(int *arr, int low, int high) {
  int temp;
  bool forward = true;
  while (low != high) {
    if (arr[high] >= arr[low]) {
      if (forward)
        high--;
      else
        low++;
      continue;
    } else {
      swap(arr[low], arr[high], temp);
      if (forward) {
        low++;
        forward = false;
      } else {
        high--;
        forward = true;
      }
    }
  }
  return low;
}

void quicksort(int *arr, int low, int high) {
  if (low < high) {
    int pivot = hoare_partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}
