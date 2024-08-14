// heapify for max heap and hence heap sort gives ascending order
#include <stdio.h>
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void heapify(int *a, int i, int n)
{
  int l, r, largest;
  largest = i;
  l = 2 * i + 1;
  r = 2 * i + 2;
  if (l < n && a[l] > a[largest])
  {
    largest = l;
  }
  if (r < n && a[r] > a[largest])
  {
    largest = r;
  }
  if (largest != i)
  {
    swap(&a[i], &a[largest]);
    heapify(a, n, largest);
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