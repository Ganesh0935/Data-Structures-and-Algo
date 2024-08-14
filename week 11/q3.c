//heapify for min heap and hence heap sort gives descending order
#include <stdio.h>
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void heapify(int *a, int i, int n)
{
  int l, r, smallest;
  smallest = i;
  l = 2 * i + 1;
  r = 2 * i + 2;
  if (l < n && a[l] < a[smallest])
  {
    smallest = l;
  }
  if (r < n && a[r] < a[smallest])
  {
    smallest = r;
  }
  if (smallest != i)
  {
    swap(&a[i], &a[smallest]);
    heapify(a, n, smallest);
  }
}
void main()
{
  int n;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  int a[n], i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for (i = (n / 2) - 1; i >= 0; i--)
  {
    heapify(a, i, n);
  }
  for (i = n - 1; i >= 0; i--)
  {
    swap(&a[0], &a[i]);
    heapify(a, 0, i);
  }
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}