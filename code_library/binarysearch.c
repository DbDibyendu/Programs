/*
Name-Dibyendu Biswas
Roll no-19E10022
Problem no-4
machine no-14
sec-4
*/
#include<stdio.h>

int main()
{
  int n,a[50],f,i,x,mid,j,k;
  printf("Enter the size:");
  scanf("%d",&n);
  printf("Enter sorter elements");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("Enter the search element:");
  scanf("%d",&x);
  printf("Press 1 for linear and 2 for binary search:");
  scanf("%d",&f);
   int  beg=0;
    int  end=n-1;
  switch(f){
  case 1:
/* logic for linear search */
    for(i=0;i<n;i++){
      if(a[i]==x){
    printf("Position:%d\n",i+1);
    k=0;
    break;
    }
      else k=1;
    }
 
    if(k==1)printf("-1\n");
    break;
  case 2:
   
/* logic for binary search */   
    while(end>=beg){
       mid=(beg+end)/2;
       if(a[mid]==x){
      printf("Position:%d\n",mid+1);
      k=0;
      break;
       }
    if(x<a[mid])
      end=mid-1;
    if(x>a[mid])
      beg=mid+1;
    k=1;
    }
     if(k==1)printf("-1\n");
    break;
  default:
    printf("Error\n");
  }
  return 0;
}
