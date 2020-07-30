#include<stdio.h>
#include<math.h>
#include<stdlib.h>



int main()
{
  int n,m,t,i=0;
  scanf("%d",&n);
  t=n;
  m=n;
  while(t>0)
  {
    if(i<n){
    if(i%2==0)
    printf("1 ");
    else
    printf("0 ");
    i++;
  }
   if((i==n)&&(m%2==0)){
      t--;
      printf("\n");
      if(t%2!=0){
      n++;
      i=1;
    }
      else{
      n--;
      i=0;
    }
    }
    if((i==n)&&(m%2!=0)){
       t--;
       printf("\n");
       if(t%2!=0){
       n--;
       i=0;
     }
       else{
       n++;
       i=1;
     }
     }
  }
  return 0;
}
