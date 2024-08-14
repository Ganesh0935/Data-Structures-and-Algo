//single linked list
//*start is to store the address of the first variable
//*p and *temp are for  traversal
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start,*p,*temp,*p1,*p2,*p3;

struct node* createll(struct node* start){
	int x,n,i;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of node(x):");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	if(start==NULL){
		start=p=temp;
	}
	else{
		p->next=temp;
		p=p->next;
	}
	}

	return start;
}



void displayll(struct node *start){
	if(start==NULL){
		printf("\nLink is empty!\n");
	}
	else{
		printf("\nThe data is:");
		p=start;
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
	}
	printf("\n");
}
void insertb(){
	int x;
	temp=(struct node*)malloc(sizeof(struct node) );
	printf("\nEnter data of node to be inserted at beginning:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		temp->next=start;
		start=temp;
	}
}
void inserte(){
	int x;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data of node to be inserted at end: ");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
	p=start;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=temp;
}
}
void insertatpos(){
	int x,pos,length=0,k=1;
	printf("\nEnter position of node to be inserted at pos:");
	scanf("%d",&pos);
	p=start;
	while(p!=NULL){
		length++;
		p=p->next;
	}
	if(pos<1 || pos>length+1){
		printf("Entered position is invalid!");
	}
	else{
		p=start;
		if(pos==1){
			insertb();
		}
		else if(pos==length+1){
			inserte();
		}
		else{
		temp=(struct node*)malloc(sizeof(struct node));
      	printf("\nEnter data of node to be inserted:");
    	scanf("%d",&x);
    	temp->data=x;
    	temp->next=NULL;
    	p=start;
    	for(k=1;k<pos-1;k++){
    		p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
		
		}
	}
	
	}
void deleteb(){
	if(start==NULL){
		printf("LL is empty");
	}
	else if(start->next==NULL){
			temp=start;
			start=NULL;
			free(temp);
		}
	else{
		temp=start;
		start=start->next;
		free(temp);
	}
}
void deletee(){
	p=start;
	if(start==NULL){
		printf("Linked list is empty!");
	}
	else if(start->next==NULL){
		temp=start;
		start=NULL;
		free(temp);
	}
	else{
	while(p->next->next!=NULL){
		p=p->next;
	}
	temp=p->next;
	p->next=NULL;
	free(temp);
	
}
}
void deletepos(){
	int pos,l=0,k;
	printf("Enter the position u want to delete!");
	scanf("%d",&pos);
	p=start;
	while(p!=NULL){
		l++;
		p=p->next;
	}
	if(pos>0 && pos<=l){
		if(pos==1){
			deleteb();
		}
		else if(pos==l){
			deletee();
		}
		else{
		p=start;
		for(k=1;k<pos-1;k++){
			p=p->next;
		}
		temp=p->next;
		p->next=temp->next;
		temp->next=NULL;
		free(temp);
		}
	} 
	else{
		printf("\nInvalid position!\n");
	}
}
void search(){
	int x,c=1,flag=0,pos;
	printf("Enter value to search:");
	scanf("%d",&x);
	p=start;
	while(p!=NULL){
		if(p->data==x){
			flag=1;
			pos=c;
			break;
		}
		p=p->next;
		c++;
	}
	if(flag==1){
		printf("Element found at position %d ",pos);
	}
	else{
		printf("Not found!");
	}
}
struct node* sortll(struct node *s){
	if(s==NULL){
		printf("Linked list is empty\n");
	}
	else if(s->next==NULL){
		printf("Linked list only contains single elements so no need of sorting!\n");
	}
	else{
		int x;
		for(p1=s;p1!=NULL;p1=p1->next){
			temp=p1;
			for(p2=p1->next;p2!=NULL;p2=p2->next){
				if(p1->data>p2->data){
					temp=p2;
				}
			}
			if(temp!=p1){
				x=temp->data;
				temp->data=p1->data;
				p1->data=x;
			}
		}
	}
  return s;
}
void reversell(){
	
	if(start==NULL){
		printf("Linked list is empty!");
	}
	else if(start->next==NULL){
		printf("single node,so no need of reversal!");
	}
	else{
		p1=start;
		p2=p1->next;
		p3=p2->next;
		p2->next=p1;
		p1->next=NULL;
		while(p3!=NULL){
			p1=p2;
			p2=p3;
			p3=p3->next;
			p2->next=p1;
		}
		start=p2;
	}
	printf("Reversal completed\n");
}

struct node* concatenatell(){
	p1=p2=NULL;
	p1=createll(p1);
	p2=createll(p2);
	p=p1;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=p2;
	start=p1;
  return start;
}

//from here all operations are for hw

void deletewithdata(){
	int x;
	printf("Enter data to be deleted:");
	scanf("%d",&x);
	p=start;
	
	if(p!=NULL && p->data==x){
		start=start->next;
		free(p);
		return ;
	}
	while(p!=NULL && p->data!=x){
		temp=p;
		p=p->next;
	}
	temp->next=p->next;
	free(p);
}

void revRecursion(struct node *prev,struct node *cur){
	if(cur->next!=NULL){
		revRecursion(cur,cur->next);
	}
	if(cur->next==NULL){
		start=cur;
	}
	cur->next=prev;
}
deleteallwithdata(){
	int x=3;
p=start;
while(p!=NULL)
{
	if(start->data==x)
	{
		temp=start;
		start=start->next;
		p=start;
		temp->next=NULL;
		free(temp);
		continue;
	}
	if(p->next->data==x)
	{
		temp=p->next;
		p->next=temp->next;
		temp->next=NULL;
		free(temp);
		continue;
	}
	p=p->next;
}
}
void merging(){
	p1=p2=NULL;
	printf("Enter elements in ascending order:");
	p1=createll(p1);
	p2=createll(p2);
	start=NULL;
	while(p1!=NULL && p2!=NULL){

		temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		if(start==NULL){
			start=p=temp;
		}
		else{
			p->next=temp;
			p=temp;
		}
		if(p1->data<=p2->data){
			temp->data=p1->data;
			p1=p1->next;
		}
		else if(p2->data<p1->data){
			temp->data=p2->data;
			p2=p2->next;
		}
		
	}

	if(p1!=NULL){
		p3=p1;
	}
	else{
		p3=p2;
	}
	while(p3!=NULL){
			
		temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		if(start==NULL){
			start=p=temp;
		}
		else{
			p->next=temp;
			p=temp;
		}
		temp->data=p3->data;
		p3=p3->next;
	}
	
}


struct node* duplicates(struct  node *start){

  p1=p2=NULL;
  for(p1=start;p1!=NULL;p1=p1->next){
    temp=p1;
    for(p2=p1->next;p2!=NULL;p2=p2->next){
    	if(p2->data==p1->data){
    	temp->next=p2->next;
    	free(p2);
		p2=temp;
		}
		temp=p2;
		p2=p2->next;
	}
  }
}
struct node* splitting(struct node *start){
	struct node *p1,*p2,*p;
	p1=p2=NULL;
	int c=0,k;
	p=p1=start;
	while(p!=NULL){
		c++;
		p=p->next;
	}
	c=c/2;
	p=start;
	for(k=1;k<c;k++){
		p=p->next;
	}
	p2=p->next;
	p->next=NULL;
	
	displayll(p1);
	displayll(p2);
}
void main(){
	int choice=1,n;
	while(choice){
	printf("\nEnter choice of operation:\n");
	printf("(1)-to create of ll\n(2)-to display ll\n(3)-to insert at beginning\n(4)-to insert at end\n(5)-to insert at specified position\n(6)-to delete from beginning\n(7)-to delete from end\n(8)-to delete from a specified position\n(9)-to search\n(10)-reversell\n(11)-to concatenate two linkedlists\n(12)-to sort\n(13)-delete based on data\n(15)-reverse with recursion\n(16)-merging of two ll\n(17)-duplicates removal\n(18)-splitting of ll\n");
	scanf("%d",&n);	 	
	switch(n){
		case 1:
	        start=createll(start);
			break;

		case 2:
			displayll(start);
			break;
		
		case 3:
	        insertb();
			break;
		
		case 4:	
	        inserte(); 
			break;
		
		case 5:{
	        insertatpos();
			break;
	
		case 6:	   
            deleteb();
			break;
		
		case 7:	  
            deletee();
			break;
		
		case 8:
			deletepos();
			break;
		
		case 9:
			search();
			break;
		
		case 10:{
			reversell();
			break;
		}
		case 11:{
			start=concatenatell();
			break;
		}
		case 12:{
			start=sortll(start);
			break;
		}
		case 13:{
			deletewithdata();
			break;
		}
		case 14:{
			deleteallwithdata();
			break;
		}
		case 15:{
			revRecursion(NULL,start);
			break;
		}
		case 16:{
			merging();
			break;
	   }
       case 17:{
      start=duplicates(start);
      break;
      }
      case 18:{
       start=splitting(start);
       break;
      }
      
	  default:{
			choice=0;
			break;
		}
		
}
}}}
