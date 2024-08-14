#include <stdio.h>
#define MAX 20
void main()
{
  int n, a[MAX], i, j, temp;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  printf("Enter the elements of array:");
  for (i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  // bubble sort
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}