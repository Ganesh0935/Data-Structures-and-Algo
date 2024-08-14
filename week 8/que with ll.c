//queue with linked list 
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
      front = enqueue(front);
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
