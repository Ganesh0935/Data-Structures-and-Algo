//#include <stdio.h>
//void swap(int *a, int *b)
//{
//  int temp = *a;
//  *a = *b;
//  *b = temp;
//}
//void quicksort(int *a, int l, int h)
//{
//  int pi;
//  if (l < h)
//  {
//    pi = partition(a, l, h);
//    quicksort(a, l, pi - 1);
//    quicksort(a, pi + 1, h);
//  }
//}
//
//int partition(int *a, int l, int h)
//{
//  int pivot, i, j;
//  pivot = a[h];
//  i = l - 1;
//  for (j = l; j < h; j++)
//  {
//    if (a[j] < pivot)
//    {
//      i++;
//      swap(&a[i], &a[j]);
//    }
//  }
//  swap(&a[i + 1], &a[h]);
//  return i + 1;
//}
//void main()
//{
//  int n, i;
//  printf("Enter the number of elements:");
//  scanf("%d", &n);
//  int a[n];
//  for (i = 0; i < n; i++)
//  {
//    scanf("%d", &a[i]);
//  }
//  quicksort(a, 0, n - 1);
//  for (i = 0; i < n; i++)
//  {
//    printf("%d ", a[i]);
//  }
//}



#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int s = low;
    int e = high;
    int m = s + (e - s) / 2;
    int pivot = arr[m];

    while (s <= e) {
        while (arr[s] < pivot) {
            s++;
        }
        while (arr[e] > pivot) {
            e--;
        }

        if (s <= e) {
            swap(&arr[s], &arr[e]);
            s++;
            e--;
        }
    }

    quick_sort(arr, low, e);
    quick_sort(arr, s, high);
}

int main() {
    int nums[] = {5, 4, 3, 2, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    quick_sort(nums, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}


