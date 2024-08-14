// double queue with array
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
void enqueue_at_front()
{
  int x;
  if (front == 0)
  {
    printf("Double ended queue is full in front\n");
  }

  else
  {
    printf("Enter data:");
    scanf("%d", &x);
    if (front == -1)
    {
      front = front + 1;
      a[front] = x;
      if (rear == -1)
      {
        rear = 0;
      }
    }
    else
    {
      front = front - 1;
      a[front] = x;
    }
  }
}
void dequeue_at_rear()
{
  if (front == -1)
  {
    printf("Double Queue is empty!\n");
  }
  else if (front == rear)
  {
    printf("Deleting element is %d\n", a[front]);
    front = rear = -1;
  }
  else
  {
    printf("Deleting element is %d\n", a[rear]);
    rear = rear - 1;
  }
}

void main()
{
  int c = 1, choice;
  while (c)
  {
    printf("Enter value of required operation:\n");
    printf("(1)-to enqueue\n(2)-to dequeue\n(3)-to traversal\n(4)-enqueue at front\n(5)-dequeue at rear\n");
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
    case 4:
    {
      enqueue_at_front();
      break;
    }
    case 5:
    {
      dequeue_at_rear();
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
