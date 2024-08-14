#include<stdio.h>
int findgcd(int a,int b,int m){
	if(a%m==0 && b%m==0){
		return m;
	}
	else{
		return findgcd(a,b,m-1);
	}
}
void main(){
	int a,b,gcd;
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	if(a>b)
    gcd=findgcd(a,b,b);
    else
    gcd=findgcd(a,b,a);
    printf("The gcd is %d",gcd);
}