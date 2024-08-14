//#include <stdio.h>
//void countingsort(int *a, int n, int place)
//{
//  int max = 0, i;
//  for (i = 0; i < n; i++)
//  {
//    if (max < (a[i] / place) % 10)
//    {
//      max = (a[i] / place) % 10;
//    }
//  }
//  int output[n], count[max + 1];
//  for (i = 0; i < max + 1; i++)
//  {
//    count[i] = 0;
//  }
//  for (i = 0; i < n; i++)
//  {
//    count[(a[i] / place) % 10]++;
//  }
//  for (i = 1; i < max + 1; i++)
//  {
//    count[i] = count[i] + count[i - 1];
//  }
//  for (i = n - 1; i >= 0; i--)
//  {
//    output[count[(a[i] / place) % 10] - 1] = a[i];
//  }
//  for (i = 0; i < n; i++)
//  {
//    a[i] = output[i];
//  }
//}
//
//void radixsort(int *a, int n)
//{
//  int max = 0, i, place = 1;
//  for (i = 0; i < n; i++)
//  {
//    if (a[i] > max)
//    {
//      max = a[i];
//    }
//  }
//  for (place = 1; max / place > 0; place = place * 10)
//  {
//    countingsort(a, n, place);
//  }
//  printf("The elements are:");
//  for (i = 0; i < n; i++)
//  {
//    printf("%d ", a[i]);
//  }
//}
//void main()
//{
//  int n;
//  printf("Enter number of elements:");
//  scanf("%d", &n);
//  int a[n], i;
//  for (i = 0; i < n; i++)
//  {
//    scanf("%d", &a[i]);
//  }
//  radixsort(a, n);
//}




#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}




void count(int arr[], int n) {
    if (arr == NULL || n <= 1) {
        return;
    }

    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* countArray = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        countArray[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (countArray[i] > 0) {
            arr[index] = i;
            index++;
            countArray[i]--;
        }
    }

    free(countArray);
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        count(arr, n);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


