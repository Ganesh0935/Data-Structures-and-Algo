#include <stdio.h>
#define MAX 5
int a[MAX];
int hash(int data)
{
  return data % MAX;
}
void insert()
{
  int value, hkey, i;
  printf("Enter value to insert:");
  scanf("%d", &value);
  hkey = hash(value);
  for (i = 0; i < MAX; i++)
  {
    if (a[hash(hkey + i * i)] == -1)
    {
      a[hash(hkey + i * i)] = value;
      printf("\nInsertion Successful!\n");
      break;
    }
  }
  if (i == MAX)
  {
    printf("\nNo space found\n");
  }
}
void display()
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    if (a[i] != -1)
      printf("%d-%d\n", i, a[i]);
    else
    {
      printf("%d-\n", i);
    }
  }
}
void searching()
{
  int value, i, hkey;
  printf("Enter value to search:");
  scanf("%d", &value);
  hkey = hash(value);
  for (i = 0; i < MAX; i++)
  {
    if (a[hash(hkey + i * i)] == value)
    {
      printf("\nElement found!\n");
      break;
    }
  }
  if (i == MAX)
  {
    printf("\nNot found!");
  }
}

void delete()
{
  int value, i, hkey;
  printf("Enter value to delete:");
  scanf("%d", &value);
  hkey = hash(value);
  for (i = 0; i < MAX; i++)
  {
    if (a[hash(hkey + i * i)] == value)
    {
      a[hash(hkey + i * i)] = -1;
      printf("\nDeletion successful\n");
      break;
    }
  }
  if (i == MAX)
  {
    printf("\nNot found!\n");
  }
}
void main()
{
  int i, c = 1, choice;
  for (i = 0; i < MAX; i++)
  {
    a[i] = -1;
  }
  while (c)
  {
    printf("\n\tMenu:");
    printf("\n\t(1)-insert\n\t(2)-delete\n\t(3)-searching\n\t(4)-display\n");
    printf("Enter choice of operation:");
    scanf("%d", &choice);
    switch (choice)
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
      searching();
      break;
    }
    case 4:
    {
      display();
      break;
    }
    default:
    {
      c = 0;
      break;
    }
    }
  }
}