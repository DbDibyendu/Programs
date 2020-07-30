#include<stdio.h>
#include<math.h>
int main()
{
  int sum=0,no,t,i=0,j=1;
  printf("Enter a number:");
  scanf("%d",&no);
  while(no!=0){
      t=no%2;
      sum=sum+t*j;
      j=j*10;
      no=no/2;
      i++;
  }
  printf("%d\n",sum);

 return 0;
}
