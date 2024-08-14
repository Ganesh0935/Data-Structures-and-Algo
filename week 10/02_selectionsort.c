//#include <stdio.h>
//#define MAX 20
//void main()
//{
//  int n, a[MAX], i, j, temp, min;
//  printf("Enter the number of elements:");
//  scanf("%d", &n);
//  printf("Enter the elements of array:");
//  for (i = 0; i < n; i++)
//  {
//    scanf("%d", &a[i]);
//  }
//  // selection sort
//  for (i = 0; i < n; i++)
//  {
//    min = i;
//    for (j = i + 1; j < n; j++)
//    {
//      if (a[j] < a[min])
//      {
//        min = j;
//      }
//    }
//    if (min != i)
//    {
//      temp = a[i];
//      a[i] = a[min];
//      a[min] = temp;
//    }
//  }
//
//  // printing
//  printf("The sorted elements are:");
//  for (i = 0; i < n; i++)
//  {
//    printf("%d ", a[i]);
//  }
//}









#include <stdio.h>

void swap(int *arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int getMaxIndex(int *arr, int start, int end) {
    int max = start;
    for (int i = start; i <= end; i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return max;
}

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int last = size - i - 1;
        int maxIndex = getMaxIndex(arr, 0, last);
        swap(arr, last, maxIndex);
    }
}

int main() {
    int nums[] = {4, 5, 1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    selectionSort(nums, size);

    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}


