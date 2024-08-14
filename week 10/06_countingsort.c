//#include <stdio.h>
//void countingSort(int *, int);
//void main()
//{
//  int n, i;
//  printf("Enter number of elements :");
//  scanf("%d", &n);
//  int p[n];
//  for (i = 0; i < n; i++)
//  {
//    scanf("%d", &p[i]);
//  }
//  countingSort(p, n);
//  printf("The elements pre:");
//  for (i = 0; i < n; i++)
//  {
//    printf("%d ", p[i]);
//  }
//}
//void countingSort(int *p, int n)
//{
//  int i = 0, max = 0, output[n];
//  for (i = 0; i < n; i++)
//  {
//    if (p[i] > max)
//    {
//      max = p[i];
//    }
//  }
//  int count[max + 1];
//  for (i = 0; i <= max; i++)
//  {
//    count[i] = 0;
//  }
//  for (i = 0; i < n; i++)
//  {
//    count[p[i]]++;
//  }
//  for (i = 1; i <= max; i++)
//  {
//    count[i] = count[i] + count[i - 1];
//  }
//  for (i = n - 1; i >= 0; i--)
//  {
//    output[count[p[i]] - 1] = p[i];
//    count[p[i]]--;
//  }
//  for (i = 0; i < n; i++)
//  {
//    p[i] = output[i];
//  }
//}



#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int arr[] = {6, 3, 10, 9, 2, 4, 9, 7};
    //int arr[] = {4, 3, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    count(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


