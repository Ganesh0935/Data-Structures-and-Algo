#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*start=NULL,*p=NULL,*temp=NULL,*p1,*p2,*p3;
struct node* createdll(struct node *start){
	int n,x,i;
	printf("Enter number of node to be created:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data of node:");
		scanf("%d",&x);
		temp->data=x;
		temp->next=temp->prev=NULL;
		if(start==NULL){
			start=p=temp;
		}
		else{
			p->next=temp;
			temp->prev=p;
			p=p->next;
		}
	}
	return start;
}
void displaydll(){
	p=start;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	
}
void insertbdll(){
	int x;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data of node to be inserted at beginning:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=temp->prev=NULL;
	if(start==NULL){
		start=p=temp;
	}
	else{
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}
void insertedll(){
	int x;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data of node to be inserted at the end:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=temp->prev=NULL;
	if(start==NULL){
		start=p=temp;
	}
	else{
		p=start;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		p=temp;
	}
}
void insertposdll(){
	int pos,k,x,l=0;
	printf("Enter position:");
	scanf("%d",&pos);
	p=start;
	while(p!=NULL){
		p=p->next;
		l++;
	}
	if(pos>0 && pos<=l+1){
	if(pos==1){
		insertbdll();
	}
	else if(pos==l+1){
		insertedll();
	}
	else{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data of node to be inserted at the given position:");
	scanf("%d",&x);	
	temp->data=x;
	temp->next=temp->prev=NULL;
	p=start;
	for(k=1;k<pos-1;k++){
		p=p->next;
	}
	temp->next=p->next;
	temp->prev=p;
	p->next=temp;
	}	
}
else{
	printf("Entered Invalid Position!");
}
}
void deletebdll(){
	if(start==NULL){
		printf("Linked List is empty!");
	}
	else{
		temp=start;
		start=start->next;
		temp->next=NULL;
		free(temp);
	}
}
void deleteedll(){
	if(start==NULL){
		printf("Linked List is empty!");
	}
	else if(start->next==NULL){
		temp=start;
		start=p=NULL;
		free(temp);
	}
	else{
		p=start;
		while(p->next->next!=NULL){
			p=p->next;
		}
		temp=p->next;
		p->next=NULL;
		temp->next=NULL;
		free(temp);
		
	}
}
void deleteposdll(){
	int pos,k,count=0;
	printf("Enter position to delete:");
	scanf("%d",&pos);
	p=start;
	while(p!=NULL){
		p=p->next;
		count++;
	}
	if(pos>0 && pos<=count){
		if(pos==1){
			deletebdll();
		}
		else if(pos==count){
			deleteedll();
		}
		else{
			p=start;
			for(k=1;k<pos;k++){
				p=p->next;
			}
        p->next->prev=p->prev;
        p->prev->next=p->next;
			p->prev=p->next=NULL;
			free(p);
		}
	  
	  }
	
	else{
		printf("Entered invalid position");
	}
	
}
void searchdll(){
		int data,c=1,pos,flag=0;
		p=start;
		if(start==NULL){
			printf("Linked list is emtpy!");
		}
		else{
		printf("Enter data to search!");
		scanf("%d",&data);
		p=start;
		while(p!=NULL){
			if(p->data==data){
				flag=1;
				pos=c;
				break;
			}
			c=c+1;
			p=p->next;
		}
		if(flag==1){
			printf("Element found at %d",pos);
		}
		else{
			printf("Element not found!");
		}
	
	}

}
void reversedll(){
	if(start==NULL){
		printf("Linked list is empty!");
	}
	else if(start->next==NULL){
		printf("Linked list contains only one element!");
	}
	else{
		p1=start;
		p2=start->next;
		p3=p2->next;
		p2->next=p1;
		p2->prev=p3;
		p1->prev=p2;
		p1->next=NULL;
		while(p3!=NULL){
			p1=p2;
			p2=p3;
			p3=p3->next;
			p2->next=p1;
			p2->prev=p3;
			
		}
		start=p2;
	}
}
void concatenatedll(){
	p1=p2=NULL;
	p1=createdll(p1);
	p2=createdll(p2);
	p=p1;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=p2;
	p2->prev=p;
	start=p1;
}


void sortdll(){
	int x;
	p1=p2=NULL;
	for(p1=start;p1!=NULL;p1=p1->next){
		for(p2=p1->next;p2!=NULL;p2=p2->next){
			if(p1->data>p2->data){
				x=p1->data;
				p1->data=p2->data;
				p2->data=x;
			}
		}
	}
}
void main(){
	int choice,c=1;
	while(c){
	printf("\nEnter choice of operation:\n");
	printf("(1)-to create of ll\n(2)-to display ll\n(3)-to insert at beginning\n(4)-to insert at end\n(5)-to insert at specified position\n(6)-to delete from beginning\n(7)-to delete from end\n(8)-to delete from a specified position\n(9)-to search\n(10)-reversell\n(11)-to concatenate two linkedlists\n(12)-to sort\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			start=createdll(start);
			break;
		}
		case 2:{
			displaydll();
	    	break;
	    }
	    case 3:{
	    	insertbdll();
			break;
		}
		case 4:{
			insertedll();
			break;
		}
		case 5:{
			insertposdll();
			break;
		}
		case 6:{
			deletebdll();
			break;
		}
		case 7:{
			deleteedll();
			break;
		}
		case 8:{
			deleteposdll();
			break;
		}
		case 9:{
			searchdll();
			break;
		}
		case 10:{
			reversedll();
			break;
		}
		case 11:{
			concatenatedll();
			break;
		}
		case 12:{
			sortdll(start);
			break;
		}
	    default:{
	    	c=0;
			break;
		}
	}
}}