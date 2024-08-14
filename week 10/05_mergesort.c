#include <stdio.h>
void merge_sort(int *p, int l, int h)
{
  int mid;
  if (l < h)
  {
    mid = (l + h) / 2;
    merge_sort(p, 0, mid);
    merge_sort(p, mid + 1, h);
    MERGE(p, l, mid, h);
  }
}
void MERGE(int *a, int l, int mid, int h)
{
  int i, j, n1, n2, k;
  n1 = mid - l + 1;
  n2 = h - mid;
  int la[n1], ra[n2];
  for (i = 0; i < n1; i++)
  {
    la[i] = a[i + l];
  }
  for (j = 0; j < n2; j++)
  {
    ra[j] = a[mid + 1 + j];
  }
  i = 0;
  j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (la[i] <= ra[j])
    {
      a[k++] = la[i++];
    }
    else
    {
      a[k++] = ra[j++];
    }
  }
  while (i < n1)
  {
    a[k++] = la[i++];
  }
  while (j < n2)
  {
    a[k++] = ra[j++];
  }
}
void main()
{
  int i, n;
  printf("Enter number of elements:");
  scanf("%d ", &n);
  int a[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 0, n - 1);
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}