#include <stdio.h>
void shellsort(int a[], int n)
{
  int interval, i, j, temp;
  for (interval = n / 2; interval > 0; interval = interval / 2)
  {
    for (i = interval; i < n; i++)
    {
      temp = a[i];
      for (j = i; j >= interval && a[j - interval] > temp; j = j - interval)
      {
        a[j] = a[j - interval]; 
      }
      a[j] = temp;  
    }
  }
}


void main()
{
  int n;
  printf("Enter number of elements:");
  scanf("%d", &n);
  int a[n], i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  shellsort(a, n);
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}
