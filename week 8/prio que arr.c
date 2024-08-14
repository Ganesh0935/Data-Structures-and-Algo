//priority queue with array
#include <stdio.h>
#define MAX 10
int arr[MAX];
int itemcount = 0;
void insert()
{
  int d, i;
  printf("Enter data:");
  scanf("%d", &d);
  if (itemcount == MAX - 1)
  {
    printf("Priority Queue is empty!");
  }
  else if (itemcount == 0)
  {
    arr[itemcount] = d;
    itemcount++;
  }
  else
  {
    for (i = itemcount - 1; i >= 0; i--)
    {
      if (d > arr[i])
      {
        arr[i + 1] = arr[i];
      }
      else
      {
        break;
      }
    }
    arr[i + 1] = d;
    itemcount++;
  }
}
void delete()
{
  if (itemcount == 0)
  {
    printf("Priority Queue is empty!");
  }
  else
  {
    printf("The deleting element is %d", arr[itemcount - 1]);
    itemcount--;
  }
}
void display()
{
  int i;
  for (i = itemcount - 1; i >= 0; i--)
  {
    printf("%d ", arr[i]);
  }
}
void main()
{
  int choice = 1, c;
  while (choice)
  {
    printf("\n(1)-insert\n(2)-delete\n(3)-display\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
    {
      insert();
      break;
    }
    case 2:
    {
      delete ();
      break;
    }
    case 3:
    {
      display();
      break;
    }
    default:
    {
      choice = 0;
      break;
    }
    }
  }
}
