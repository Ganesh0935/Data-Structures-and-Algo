#include<stdio.h>
struct student{
	int id;
	char name[20];
};
void main(){
	int n,i;
	printf("Enter number of students:");
	scanf("%d ",&n);
	struct student s[n];
	printf("Enter details of students:\n");
	for(i=0;i<n;i++){
	printf("Student-%d\n",i+1);
	printf("Enter id:");
	scanf("%d",&s[i].id);
	printf("Enter name:");
	scanf("%s",s[i].name);
	}
	for(i=0;i<n;i++){
		printf("Student-%d:\n",i+1);
		printf("Id is %d and name is %s.\n",s[i].id,s[i].name);
	}
	
}