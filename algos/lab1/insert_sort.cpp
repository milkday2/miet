void insert_sort(int *arr, int len) {
  int key;
  int j;
  for (int i = 1; i < len; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j+1]=key;
  }
}

