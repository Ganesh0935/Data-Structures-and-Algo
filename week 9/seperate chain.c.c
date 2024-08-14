#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct node
{
  int data;
  struct node *next;
} *temp, *a[SIZE], *p;
void initialize()
{
  int i = 0;
  for (i = 0; i < SIZE; i++)
  {
    a[i] = NULL;
  }
}
void insert(int value)
{
  int hkey;
  struct node *temp, *p;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = value;
  temp->next = NULL;
  hkey = value % SIZE;
  if (a[hkey] == NULL)
  {
    a[hkey] = temp;
  }
  else
  {
    p = a[hkey];
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = temp;
  }
}
void delete(int value)
{
  int hkey;
  hkey = value % SIZE;
  if (a[hkey] == NULL)
  {
    printf("\nCorresponding Chain is empty!");
  }
  else
  {
    p = a[hkey];
    if (p->data == value)
    {
      printf("Deleting value is %d\n", p->data);
      a[hkey] = p->next;
    }
    else
    {
      p = a[hkey];
      while (p->next != NULL)
      {
        if (p->next->data == value)
        {
          temp = p->next;
          p->next = temp->next;
          temp->next = NULL;
          free(temp);
          break;
        }
        p = p->next;
      }
    }
  }
}
void display()
{
  int i;
  for (i = 0; i < SIZE; i++)
{
    printf("%d--", i);
    p = a[i];

    while (p != NULL)
    {
      printf("%d", p->data);
      p = p->next;
    }
    printf("\n");
  }
}

void main()
{
  initialize();
  int c = 1, choice, value;
  while (c)
  {
    printf("Enter choice of operation:\n");
    printf("(1)-insert\n(2)-delete\n(3)-display\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter value:");
      scanf("%d", &value);
      insert(value);
      break;
    case 2:
    {
      printf("Enter value:");
      scanf("%d", &value);
      delete (value);
      break;
    }
    case 3:
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
