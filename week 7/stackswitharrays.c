// stack with array
#include <stdio.h>
#define MAX 100
int a[MAX], top = -1;
void push(int);
int pop();
void traversal();
void main()
{
  int c, x, choice = 1;
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
      push(x);
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
void push(int x)
{
  if (top >= MAX - 1)
  {
    printf("Stack is full!\n");
  }
  else
  {
    top = top + 1;
    a[top] = x;
  }
}

int pop()
{
  if (top == -1)
  {
    printf("Stack is empty!");
  }
  else
  {
    return a[top--];
  }
}

void traversal()
{
  int i;
  if (top == -1)
  {
    printf("\nStack is empty!");
  }
  else
  {
    printf("\nThe elements are:");
    for (i = top; i >= 0; i--)
    {
      printf("%d ", a[i]);
    }
  }
}
