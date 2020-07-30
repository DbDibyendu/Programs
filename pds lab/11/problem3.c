/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-3
sec-4
*/
#include<stdio.h>
#include<stdlib.h>

int main() {

    int n,a[20],i,j,t,m;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter the elements:");
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
    printf("\nEnter m(between 1 to %d):",n);
    scanf("%d",&m);
    printf("\nSmallest %d elements in order:",m);
    for(i=0;i<m;i++)
    printf("%d ",a[i]);

    return 0;
}
