#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int a=0,b,d,n,t,j;
  scanf("%d",&t);
  while(t){
    a=0;
    scanf("%d",&n);
    d=n;
    for(int i=2;i<=sqrt(d);i++){
      if(d%i==0){
        a++;
        d=d/i;
        j=i;
      }
    }
    if(d>j) a++; //important......when the remaining factor is greater than the last greatest distinct factor....
    if(a>=3){
      printf("Yes\n");
      b=0;
      d=n;
      for(int i=2;i<=sqrt(d);++i){
        if(d%i==0){
          b++;
          d=d/i;
          if(b<3)
          printf("%d ",i);
        if(b==2)
        printf("%d \n",d);
        }
      }
    }
    else printf("No\n");
    t--;
  }
  return 0;
}
