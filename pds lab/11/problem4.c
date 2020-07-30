/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-4
sec-4
*/
#include<stdio.h>
#include<stdlib.h>

int main() {

    int n,a[20],i,j,t,p,q,end,beg,mid,l,h,k;
    do {
      printf("Enter n(between 1 to 20):");
      scanf("%d",&n);
    } while(n>20);

    printf("Enter the sorted elements(integers only):");
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    // applying bubblesort
    for(i=0;i<n;i++)
      for(j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    printf("\nEnter the interval endpoints(p & q)");
    scanf("%d%d",&p,&q);
    end=n-1;
    beg=0;
    if(k==1)printf("-1\n");
    end=n-1;
    beg=0;
    // finding lower limit
    while(end>=beg){
       mid=(beg+end)/2;
       if((p<=a[mid])&&(p>=a[mid-1])){
    //  printf("Position:%d\n",mid);
      l=mid;
      k=0;
      break;
       }
    if(p<a[mid])
      end=mid-1;
    if(p>a[mid])
      beg=mid+1;
    k=1;
    }
    end=n-1;
    beg=0;
    // finding upper limit
    while(end>=beg){
       mid=(beg+end)/2;
       if((q>=a[mid])&&(q<=a[mid+1])){
    //  printf("Position:%d\n",mid);
      h=mid;
      k=0;
      if(q==a[mid+1])h=mid+1;
      break;
       }
    if(q<a[mid])
      end=mid-1;
    if(q>a[mid])
      beg=mid+1;
    k=1;
    }
    // extra conditions
    if(p<a[0]) l=0;
    if(q>a[n-1]) h=n-1;


      printf("Elements in the interval:");
      // printing different cases....
       if(q==a[0]) printf("%d",q);
      else if(p==a[n-1]) printf("%d",p);
      else if(l>=h)
      printf("None");
      else if(k==1)
      printf("None");
      else
      for(i=l;i<=h;i++){
        printf("%d ",a[i]);
      }
    return 0;
}
