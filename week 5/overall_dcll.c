#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev,*next;
}*start=NULL,*end,*temp,*p,*p1=NULL,*p2=NULL,*p3=NULL;
struct node* createdcll(struct node *start){
	int n,i;
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data of node:");
	scanf("%d",&temp->data);
	temp->next=temp->prev=NULL;
	if(start==NULL){
		start=end=temp;
		start->next=start->prev=start;
	}
	else{
		end->next=temp;
		temp->prev=end;
		temp->next=start;
		start->prev=temp;
		end=temp;
	}
}
return start;
}
struct node* displaydcll(struct node *start){
	p=start;
	do{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=start);
	return start;
}
void insertbdcll(){
	
	if(start==NULL){
		printf("\nLinked list is empty!");
	}
	else{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data of node to be inserted in the beginning:");
	scanf("%d",&temp->data);
		temp->next=start;
		start->prev=temp;
		start=temp;
		start->prev=end;
		end->next=start;
	}
	
	
}
void insertedcll(){
	if(start==NULL){
		printf("\nLinked List is empty!");
	}
	else{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data of node to be inserted at the end:");
		scanf("%d",&temp->data);
		end->next=temp;
		temp->prev=end;
		end=temp;
		start->prev=end;
		end->next=start;
		
	}
}
void insertposdcll(){
	int pos,k,l=0;
	if(start==NULL){
		printf("Linked list is empty!");
		return ;
	}
	printf("\nEnter position in which the node to be inserted :");
	scanf("%d",&pos);
	p=start;
	do{
		l=l+1;
		p=p->next;
	}while(p!=start);
	if((pos>=1 && pos<=l+1)||pos==1){
		if(pos==1){
			insertbdcll();
		}
		else if(pos==l+1){
			insertedcll();
		}
		else{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter data of node to be inserted at the position:");
			scanf("%d",&temp->data);
			p=start;
			for(k=1;k<pos-1;k++){
				p=p->next;
			}
			temp->next=p->next;
			p->next->prev=temp;
			p->next=temp;
			temp->prev=p;
		}
	}
	else{
		printf("\nInvalid position");
	}
}
void deletebdcll(){
	if(start==NULL){
		printf("\nLinked LIst is empty!");
	}
	else if(start->next==start){
		start->next=start->prev=NULL;
		end->next=end->prev=NULL;
		free(start);
	}
	else{
		temp=start;
		start=start->next;
		start->prev=end;
		end->next=start;
		temp->next=temp->prev=NULL;
		free(temp);
	}
}
void deleteedcll(){
	if(start==NULL){
		printf("\nLinked List is empty!");
	}
	else if(start->next==start){
		temp=start;
		start->next=start->prev=end->next=end->prev=NULL;
		free(temp);
	}
	else{
		temp=end;
		end=end->prev;
		end->next=start;
		start->prev=end;
		temp->next=temp->prev=NULL;
		free(temp);
	}
}
void deleteposdcll(){
	int pos,k,l=0;
	printf("\nEnter position to be deleted:");
	scanf("%d",&pos);
	p=start;
	do{
		l++;p=p->next;
	}while(p!=start);
	if(pos>0 && pos<=l){
		if(pos==1){
			deletebdcll();
		}
		else if(pos==l){
		
			deleteedcll();
		}
		else{
			p=start;
			for(k=1;k<pos;k++){
				p=p->next;
			}
			p->prev->next=p->next;
			p->next->prev=p->prev;
			p->next=p->prev=NULL;
			free(p);
			
		}
	}
	else{
		printf("\nEntered Invalid Position!");
	}
	
}
void searchdcll(){
	int x,flag=0,c=1,pos;
	printf("\nEnter data to be searched:");
	scanf("%d",&x);
	p=start;
	do{
		if(p->data==x){
			flag=1;
			pos=c;
			break;
		}
		p=p->next;
		c++;
	}while(p!=start);
	if(flag==1){
		printf("\nElement found at %d",pos);
	}
	else{
		printf("\nElement not found!");
	}
}
void reversedcll(){
	if(start==NULL){
		printf("\nLinked List is empty!");
	}
	else if(start->next==start){
		printf("\nNo need of reversal");
	}
	else{
		p1=start;
		p2=p1->next;
		p3=p2->next;
		p1->next=end;
		p1->prev=p2;
		p2->next=p1;
		p2->prev=p3;
		end=p1;
		while(p3!=start){
			p1=p2;
			p2=p3;
			p3=p2->next;
			p2->next=p1;
			p2->prev=p3;
		}
		p2->prev=end;
		start=p2;
	}
}
void concatenatedcll(){
	p1=createdcll(p1);
	p2=createdcll(p2);
	p=p1;
	while(p->next!=p1){
		p=p->next;
	}
	p->next=p2;
	p2->prev=p;
	p=p2;
	while(p->next!=p2){
		p=p->next;
	}
	p->next=p1;
	p1->prev=p;
	start=p1;
}

void sortdcll(struct node *start){
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
	int choice=1,c;
	while(choice){
	printf("\nEnter choice of your opeartions:");
	printf("(1)-to create of ll\n(2)-to display ll\n(3)-to insert at beginning\n(4)-to insert at end\n(5)-to insert at specified position\n(6)-to delete from beginning\n(7)-to delete from end\n(8)-to delete from a specified position\n(9)-to search\n(10)-reversell\n(11)-to concatenate two linkedlists\n(12)-to sort the double circular linked list\n");
	scanf("%d",&c);
	switch(c){
		case 1:{
			start=createdcll(start);
			break;
		}
		case 2:{
			start=displaydcll(start);
			break;
		}
		case 3:{
			insertbdcll();
			break;
		}
		case 4:{
		insertedcll();
		break;
		}
		case 5:{
			insertposdcll();
			break;
		}
		case 6:{
			deletebdcll();
			break;
		}
		case 7:{
			deleteedcll();
			break;
		}
		case 8:{
			deleteposdcll();
			break;
		}
		case 9:{
			searchdcll();
			break;
		}
		case 10:{
			reversedcll();
			break;
		}
		case 11:{
			concatenatedcll();
			break;
		}
		case 12:{
			sortdcll(start);
			break;
		}
		default:{
			choice=0;
			break;
		}
		
	}
}
}
