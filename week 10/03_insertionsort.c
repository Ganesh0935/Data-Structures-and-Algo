//#include <stdio.h>
//#define MAX 20
//void main()
//{
//  int n, a[MAX], i, j, temp, key;
//  printf("Enter the number of elements:");
//  scanf("%d", &n);
//  printf("Enter the elements of array:");
//  for (i = 0; i < n; i++){
//    scanf("%d", &a[i]);
//  }
//  // insertion sort
//  for (i = 1; i < n; i++)
//  {
//    j = i - 1;
//    key = a[i];
//    while (j >= 0 && a[j] > key)
//    {
//      a[j + 1] = a[j];
//      j--;
//    }
//    a[j + 1] = key;
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

void insertion(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else {
                break;
            }
        }
    }
}

int main() {
    int nums[] = {5, 3, 4, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    insertion(nums, size);

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


