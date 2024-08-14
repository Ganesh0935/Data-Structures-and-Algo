#include <stdio.h>
#define MAX 20
int  binsearch(int *p,int l,int h,int x){
  int mid;
  while(l<=h){
    mid=(l+h)/2;
    if(p[mid]==x){
      return mid;
    }
    else if(p[mid]<x){
      l=mid-1;
    }
    else if(p[mid]>x){
      h=mid+1;
    }
  }
  return -1;
}
void main()
{
  int n, a[MAX], i, x;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  printf("Enter the elements of array in ascending order:");
  for (i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  printf("Enter the element to search:");
  scanf("%d", &x);
  int res=binsearch(a,0,n-1,x);
  if(res==-1){
  printf("Element not found!");
  }
  else{
  printf("Element found at %d ",res);
 }
 }
