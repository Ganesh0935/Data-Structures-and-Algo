// implementation of stacks with linkedlist
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
} *top = NULL, *p, *temp;
struct node *push(int);
int pop();
void traversal();
void main()
{
  int choice = 1, c, x;
  while (choice)
  {
    printf("\nEnter the choice of your operation:\n");
    printf("\n(1)-push data into the stack\n(2)-to pop data from stack\n(3)-to traverse the stack\n(0)-to exit!\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
    {
      printf("\nEnter the value of x:");
      scanf("%d", &x);
      top = push(x);
      break;
    }
    case 2:
    {
      x = pop();
      printf("\nThe deleted element is %d\n", x);
      break;
    }
    case 3:
    {
      traversal();
      break;
    }
    case 0:
    {
      choice = 0;
      break;
    }
    }
  }
}
struct node *push(int x)
{
  temp = (struct node *)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = x;
  if (top == NULL)
  {
    top = temp;
  }
  else
  {
    temp->next = top;
    top = temp;
  }
  return top;
}

int pop()
{
  int x;
  if (top == NULL)
  {
    printf("\nThe stack is empty!");
  }
  else
  {
    x = top->data;
    temp = top;
    top = top->next;
    temp->next = NULL;
    free(temp);
  }
  return x;
}

void traversal()
{
  if (top == NULL)
  {
    printf("\nStack is empty!");
  }
  else
  {
    p = top;
    printf("The data are:");
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}
