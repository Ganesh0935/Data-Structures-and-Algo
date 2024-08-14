//fouble queue with linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
} *front = NULL, *rear = NULL, *temp, *p;
struct node *enqueue(struct node *front)
{
  int x;
  printf("Enter data of node:");
  scanf("%d", &x);
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;
  if (rear == NULL)
  {
    front = rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = temp;
  }
  return front;
}
void dequeue()
{
  if (front == NULL)
  {
    printf("Queue is empty!\n");
  }
  else if (front == rear)
  {

    printf("The deleting element is %d\n", front->data);
    front = rear = NULL;
  }
  else
  {
    temp = front;
    printf("The deleting element is %d\n", temp->data);
    front = front->next;
    temp->next = NULL;
    free(temp);
  }
}

void traversal()
{
  if (front == NULL)
  {
    printf("It is empty!\n");
  }
  else
  {
    p = front;
    while (p != NULL)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}

void enqueue_at_front()
{
  int x;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("Enter data :");
  scanf("%d", &x);
  temp->data = x;
  temp->next = NULL;

  if (front == NULL)
  {
    front = rear = temp;
  }
  else
  {
    temp->next = front;
    front = temp;
  }
}

void dequeue_at_rear()
{
  if (front == NULL)
  {
    printf("Circular Queue is empty!\n");
  }
  else if (front->next == NULL)
  {
    front = rear = NULL;
  }
  else
  {
    p = front;
    while (p->next->next != NULL)
    {
      p = p->next;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
  }
}
void main()
{
  int c = 1, choice;
  while (c)
  {
    printf("Enter the value of operation:\n");
    printf("(1)-enqueue\n(2)-traversal\n(3)-dequeue\n(4)-enqueue at front\n(5)-delete at rear\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      front = enqueue(front);
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
