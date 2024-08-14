#include<stdio.h>
#include<stdlib.h>
struct node{
    float co;
    int expo;
    struct node* next;
};

struct node* insert(struct node* head,float co,int expo)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->co=co;
    temp->expo=expo;
    temp->next=NULL;
    if(head==NULL || head->expo<expo)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        struct node* temp1=head;
        while(temp1->next!=NULL && temp1->next->expo>=expo)
        {
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    return head;
}

struct node* add(struct node* head,struct node* head1)
{
    struct node* temp=head;
    struct node* temp1=head1;
    struct node* head2=NULL;
    
    while(temp!=NULL && temp1!=NULL)
    {
        if(temp->expo==temp1->expo)
        {
            head2=insert(head2,temp->co+temp1->co,temp->expo);
            temp=temp->next;
            temp1=temp1->next;
        }
        else if(temp->expo>temp1->expo)
        {
            head2=insert(head2,temp->co,temp->expo);
            temp=temp->next;
        }
        else if(temp1->expo>temp->expo)
        {
            head2=insert(head2,temp1->co,temp1->expo);
            temp1=temp1->next;
        }
    }
    while(temp!=NULL)
    {
        head2=insert(head2,temp->co,temp->expo);
        temp=temp->next;
    }
    while(temp1!=NULL)
    {
        head2=insert(head2,temp1->co,temp1->expo);
        temp1=temp1->next;
    }
    return head2;
}


struct node* create(struct node* head)
{
    int n,expo;
    float co;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the coefficient of term %d: ",i+1);
        scanf("%f",&co);
        printf("\nEnter the exponent of term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,co,expo);
    }
    printf("\n\n");
    return head;
}

int main()
{
    struct node* head=NULL;
    struct node* head1=NULL;
    struct node* head2=NULL;
    head=create(head);
    head1=create(head1);
    head2=add(head,head1); 
    struct node* ptr=head2;
    while(ptr!=NULL)
    {
        printf("(%.1fx^%d)",ptr->co,ptr->expo);
        ptr=ptr->next;
        if(ptr!=NULL)
        {
            printf("+");
        }
        else
        printf("\n");
        
        
    }
}
