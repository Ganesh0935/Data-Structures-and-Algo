//priority queue with linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next;
} *start = NULL, *p = NULL, *temp = NULL;
void insert(){
  int d;
  printf("Enter data :");
  scanf("%d", &d);
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = d;
  temp->next = NULL;
  if (start == NULL || d>start->data)
  {
    temp->next = start;
    start = temp;
  }
  else
  {
    p = start;
    while (p->next != NULL && p->next->data > d){
      p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
  }
}
void delete()
{
  if (start == NULL)
  {
    printf("Priority Queue is empty!\n");
  }
  else if (start->next == NULL)
  {
    temp = start;
    start = NULL;
    free(temp);
  }
  else
  {
    p = start;
    while (p->next->next != NULL)
    {
      p = p->next;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
  }
}
void display()
{
  p = start;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}
void main()
{
  int choice = 1, c;
  while (choice)
  {
    printf("\n(1)-insert\n(2)-delete\n(3)-display\n");
    scanf("%d", &c);
    switch (c)
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
      display();
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
      choice = 0;
      break;
    }
    }
  }
}
