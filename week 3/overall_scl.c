#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL,*end=NULL,*p=NULL,*temp=NULL,*p1=NULL,*p2=NULL,*p3=NULL;
struct node* createscl(struct node *start){
	int n,i,x;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data of node:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	
		if(start==NULL){
			start=temp;
			end=temp;
			start->next=start;
		}
		else{
			end->next=temp;
			end=temp;
			end->next=start;
		}
	}
	return start;
}
void displayscl(){
	p=start;
	do{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=start);
}

void insertbscl(){
	int x;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data of node at beginning:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	
	if(start==NULL){
		start=end=temp;
		temp->next=temp;
	}
	else{
		temp->next=start;
		start=temp;
		end->next=temp;
	}
}
void insertescl(){
	int x;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert at end:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	if(start==NULL){
		start=end=temp;
		start->next=start;
	}
	else{
		end->next=temp;
		end=temp;
		end->next=start;
	}
}
void insertposscl(){
	int x,pos,l=1,k=1;
	printf("Enter position:");
	scanf("%d",&pos);
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert at pos:");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	p=start;
	while(p->next!=start){
		p=p->next;
		l++;
	}
	if(pos>0 && pos<=l+1){
		if(pos==1){
		insertbscl();
		}
		else if(pos==l+1){
			insertescl();
		}
		else{
			p=start;
			for(k=1;k<pos-1;k++){
				p=p->next;
			}
			temp->next=p->next;
			p->next=temp;
			
		}
	}
	else{
		printf("Invalid position!");
	}

	
}
void deletebscl(){
	if(start==NULL){
		printf("Linked list is empty!");
	}
	else if(start->next==start){
		start->next=NULL;
		free(start);
		free(end);
	}
	else{
		temp=start;
		start=start->next;
		end->next=start;
		temp->next=NULL;
		free(temp);
	}
}
void deleteescl(){
	if(start==NULL){
		printf("Linked list is empty!");
	}
	else if(start->next==NULL){
		start->next=NULL;
		free(start);
		free(end);
	}
	else{
		p=start;
		while(p->next->next!=start){
			p=p->next;
		}
		temp=end;// temp=p->next;
		p->next=start;
		temp->next=NULL;
		free(temp);
		end=p;	
	}
}
void deleteposscl(){
	int l=1,pos,k;
	printf("Enter position:");
	scanf("%d",&pos);
	p=start;
	while(p->next!=start){
		p=p->next;
		l=l+1;
	}
	if(pos>0 && pos<=l){
		if(pos==1){
			deletebscl();
		}
		else if(pos==l){
			deleteescl();
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
		printf("Invalid position!");
	}
}

void searchscl(){
	int x,flag=0,c=1,pos;
	printf("Enter data to search:");
	scanf("%d",&x);
	p=start;
	do{
		if(p->data==x){
			flag=1;
			pos=c;
			break;
		}
		c++;
	p=p->next;
	}while(p!=start);
	if(flag==1){
		printf("Element found at position %d!",pos);
	}
	else{
		printf("No element found ");
	}
} 
void reversescl(){
	if(start==NULL){
		printf("Linked list is empty!");
	}
	else if(start->next==start){
		printf("Linked list contains only one element so no need to reverse");
	}
	else{
		p1=start;
		p2=start->next;
		
		p3=start->next->next; //or p3=p2->next;
		p2->next=p1;
		p1->next=end;
		end=p1;
		while(p3!=start){
			p1=p2;
			p2=p3;
			p3=p3->next;
			p2->next=p1;
		}
		start=p2;
	}
}
void concatenatescl(){
	p1=p2=NULL;
	p1=createscl(p1);
	p2=createscl(p2);
	start=p=p1;
	while(p->next!=start){
		p=p->next;
	}
	p->next=p2;
	p=start=p2;
	while(p->next!=start){
		p=p->next;
	}
	p->next=p1;
	end=p;
	start=p1;

}
void sortscl(struct node *start){
	int x;
	p1=p2=NULL;
	end->next=NULL;
	for(p1=start;p1!=NULL;p1=p1->next){
		for(p2=p1->next;p2!=NULL;p2=p2->next){
			if(p1->data>p2->data){
				x=p1->data;
				p1->data=p2->data;
				p2->data=x;
			}
		}
	}
	end->next=start;
}
void main(){
	int choice,c=1,pos;
	while(c){
		
	printf("\nEnter choice of operation:\n");
	printf("(1)-to create of ll\n(2)-to display ll\n(3)-to insert at beginning\n(4)-to insert at end\n(5)-to insert at specified position\n(6)-to delete from beginning\n(7)-to delete from end\n(8)-to delete from a specified position\n(9)-to search\n(10)-reversell\n(11)-to concatenate two linkedlists\n(12)-to sort the single circular linked list");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:{
			
	start=createscl(start);
			break;
		}
		case 2:{
			displayscl();
			break;
		}
		case 3:{	
	insertbscl();
			break;
		}case 4:{
		
	insertescl();	
			break;
		}
		case 5:{
		
	insertposscl();	
			break;
		}case 6:{
			
	deletebscl();
			break;
		}
		case 7:{
		
	deleteescl();	
			break;
		}
		case 8:{
			deleteposscl();
			break;
		}
		case 9:{
			searchscl();
			break;
		}
		case 10:{
			reversescl();
			break;
		}
		case 11:{
			concatenatescl();
			break;
		}
		case 12:{
			sortscl(start);
			break;
		}
		default:{
			c=0;
			break;
		}
		
	}
}
}
