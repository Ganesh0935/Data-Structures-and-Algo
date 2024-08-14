#include <stdio.h>
#define MAX 20
void main()
{
  int n,a[MAX],i,x;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  printf("Enter the elements of array:");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter the element to search:");
  scanf("%d", &x);
  for (i = 0; i < n; i++)
  {
    if (a[i] == x)
    {
    	break;
    }
  }
  if( i != n){
  	printf("Element found at index %d position", i);
  }
  else{
  	printf("Element not found ");
  }
  
   
}
