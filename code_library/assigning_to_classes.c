#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int swap();
int partition();
int quicksort();


int main()
{
  int t,n,i,k,j,x;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    n=2*n;
    int a[n];
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    quicksort(a,0,n);
      k=a[n/2]-a[n/2-1];
      printf("%d\n",k);
  }

  return 0;
}

int swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}


int partition(int a[100000],int l,int h)
{
  int first=a[l];
  int i=l,j=h;
  while(i<j){
  do {
      i++;
  } while(a[i]<first);

  do {
    j--;
  } while(a[j]>first);

  if(i<j){
  swap(&a[i],&a[j]);
    }
  }
    swap(&a[j],&a[l]);
   return j;
}
int quicksort(int a[100000],int l,int h)
{
  int j;
  if(l<h)
  {
    j=partition(a,l,h);
    quicksort(a,l,j);
    quicksort(a,j+1,h);
  }
}
