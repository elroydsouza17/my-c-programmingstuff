#include <stdio.h>

int BinarySearch(int* arr, int low, int high, int target);

int main() {
  int array[] = {1, 2, 3, 4, 5, 5, 6, 7, 11, 15};
  int index = BinarySearch(array, 0, 9, 16);
  printf("Index of target: %d\n", index);
  return 0;
}

int BinarySearch(int* arr, int low, int high, int target) {
  if (low > high) {
    return -1;
  }

  int mid = low + (high - low) / 2;

  if (arr[mid] == target) {
    return mid;
  } 

  if (target < arr[mid]) {
    mid = BinarySearch(arr, low, mid - 1, target);
  } else {
    mid = BinarySearch(arr, mid + 1, high, target);
  }

  return mid;
}

