//circular queue with linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
} *start = NULL, *end = NULL, *p = NULL, *temp = NULL;
struct node *enqueue(struct node *start)
{
  int i, x;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("Enter data :");
  scanf("%d", &x);
  temp->data = x;
  temp->next = NULL;

  if (start == NULL)
  {
    start = temp;
    end = temp;
    start->next = start;
  }
  else
  {
    end->next = temp;
    end = temp;
    end->next = start;
  }

  return start;
}
void traversal()
{
  p = start;
  do
  {
    printf("%d ", p->data);
    p = p->next;
  } while (p != start);
}

void dequeue()
{
  if (start == NULL)
  {
    printf("Circular Queue is empty!\n");
  }
  else if (start->next == start)
  {
    start->next = NULL;
    start = NULL;
    free(start);
    free(end);
  }
  else
  {
    temp = start;
    start = start->next;
    end->next = start;
    temp->next = NULL;
    free(temp);
  }
}
void main()
{
  int c = 0, choice = 1;
  while (choice)
  {
    printf("Enter the value of operation:\n");
    printf("(1)-enqueue\n(2)-traversal\n(3)-dequeue\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
    {
      start = enqueue(start);
      break;
    }
    case 2:
    {
      traversal();
      break;
    }
    case 3:
    {
      dequeue();
      break;
    }
    }
  }
}
