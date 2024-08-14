#include <stdio.h>
#define MAX 5
int a[MAX];
int p;
void get_prime()
{
  int i, j, c = 0;
  for (i = MAX; i >= 0; i--)
  {
    c = 0;
    for (j = 1; j <= i; j++)
    {
      if (i % j == 0)
      {
        c++;
      }
    }
    if (c == 2)
    {
      p = i;
      break;
    }
  }
  printf("Prime is %d\n", p);
}
int hash(int data)
{
  return data % MAX;
}
void insert()
{
  int value, hkey1, hkey2, i;
  printf("Enter value to insert:");
  scanf("%d", &value);
  hkey1 = hash(value);
  hkey2 = p - (value % p);
  for (i = 0; i < MAX; i++)
  {
    if (a[hash(hkey1 + i * hkey2)] == -1)
    {
      a[hash(hkey1 + i * hkey2)] = value;
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
  int value, i, hkey1, hkey2;
  printf("Enter value to search:");
  scanf("%d", &value);
  hkey1 = hash(value);
  hkey2 = p - (value % p);
  for (i = 0; i < MAX; i++)
  {
    if (a[hash(hkey1 + i * hkey2)] == value)
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
  int value, i, hkey1, hkey2;
  printf("Enter value to delete:");
  scanf("%d", &value);
  hkey1 = hash(value);
  hkey2 = p - (value % p);
  for (i = 0; i < MAX; i++)
  {
    if (a[hash(hkey1 + i * hkey2)] == value)
    {
      a[hash(hkey1 + i * hkey2)] = -1;
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
  get_prime();
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