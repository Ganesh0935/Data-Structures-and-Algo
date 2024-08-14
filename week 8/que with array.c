//queue with array
#include <stdio.h>
#define MAX 10
int a[MAX], front = -1, rear = -1;
void enqueue()
{
  int x;
  if (rear >= MAX - 1)
  {
    printf("Queue is full\n");
  }
  else
  {
    printf("Enter data:");
    scanf("%d", &x);
    rear = rear + 1;
    a[rear] = x;
    if (front == -1)
    {
      front = 0;
    }
  }
}
void dequeue()
{
  if (front == -1)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Deleting element is %d", a[front]);
    front = front + 1;
  }
}
void traversal()
{
  int i;
  if (front == -1)
  {
    printf("Queue is empty!\n");
  }
  else
  {
    for (i = front; i <= rear; i++)
    {
      printf("%d ", a[i]);
    }
  }
}
void main()
{
  int c = 1, choice;
  while (c)
  {
    printf("(1)-enqueue operation\n(2)-dequeue operation\n(3)-traversal\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      enqueue();
      break;
    }
    case 2:
    {
      dequeue();
      break;
    }
    case 3:
    {
      traversal();
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
