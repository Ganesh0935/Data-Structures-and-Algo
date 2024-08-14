// circular queue
#include <stdio.h>
#define MAX 4
int CQ[MAX] = {0}, front = -1, rear = -1;
void enqueue()
{
  int x;
  if (front == (rear + 1) % MAX)
  {
    printf("Circular Queue is full!\n");
  }
  else
  {
    printf("Enter the data :");
    scanf("%d", &x);
    rear = (rear + 1) % MAX;
    CQ[rear] = x;
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
    printf("Circular Queue is empty!\n");
  }
  else if (front == rear)
  {
    printf("The deleting element is %d\n", CQ[front]);
    front = rear = -1;
  }  
  else
  {
    front = (front + 1) % MAX;
  }
  printf("\n");
}
void traversal()
{
  int i;
  if (front == -1)
  {
    printf("Circular Queue is empty!\n");
  }
  else
  {
    printf("The elements are :");
    i = front;
    do
    {
      printf("%d ", CQ[i]);
      i = (i + 1) % MAX;

    } while (i != (rear + 1) % MAX);
  }
  printf("\n");
}

void main()
{
  int choice = 1, c, i;
  while (choice)
  {
    printf("Enter value of required operation:\n");
    printf("(1)-to enqueue\n(2)-to dequeue\n(3)-to traversal\n");
    scanf("%d", &c);
    switch (c)
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
