#include<stdio.h>
void main(){
    int r1,r2,c1,c2,i,j,k,sum=0;
    printf("Enter rows and columns of matrix 1:");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns of matrix 2:");
    scanf("%d %d",&r2,&c2);
    
    if(c1!=r2){
    	printf("Can't be multiplied!");
        //exit();
	}
    int a[r1][c1],b[r2][c2],mul[r1][c2];
    printf("Enter elements of matrix 1:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("Enter elements of matrix 2:\n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&a[i][j]);
        }
        
        printf("\n");
    }
    
    
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				sum=0;
				for(k=0;k<r2;k++){
					sum=sum+a[i][k]*a[k][j];
				}
			mul[i][j]=sum;
			}
		}
	printf("The product of matrix are:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d ",mul[i][j]);
		}
		printf("\n");
	}	
}
