#include<stdio.h>
#include<math.h>
int fib(int i){
	if(i==0)
	return 0;
	else if(i==1){
		return 1;
	}
	else{
		return fib(i-1)+fib(i-2);
	}
}
void main(){
	int n,i;
	printf("Enter number of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d ",fib(i));
	}
	
	int num;
	printf("\nEnter the number of fibonacci numbers:");
	scanf("%d",&num);
	for(int j = 0 ; j <num; j++)
	{
		float r = 144*(pow(1.619,(j-12)));
		printf("%.0f ",round(r));
	}
}
