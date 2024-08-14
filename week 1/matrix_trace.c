#include<stdio.h>
void main(){
	int r,c,i,j,s=0; 
	printf("Enter rows and columns:");
	scanf("%d %d",&r,&c);
	if(r!=c){
		printf("Trace can't be found!");
	}
	else{
	int a[r][c];  
	printf("Enter elements of array:");
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(i==j)
			s=s+a[i][j];
		}
	}
	
	printf("The trace is %d",s);
}
}