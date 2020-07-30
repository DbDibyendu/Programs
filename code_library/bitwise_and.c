#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int binary();
int and();
int main()
{
  int a,b,sum1,sum2,sum3,t1,t2,t3;
  scanf("%d%d",&a,&b);
  sum1=binary(a);
  sum2=binary(b);
  printf("%d\n",sum1);
    printf("%d\n",sum2);
    t1=binary(a);
    t2=binary(a+1);
  for(int i=a+1;i<=b;i++)
  {
      t3=and(t1,t2);
      t1=binary(i+1);
      t2=t3;

  }

  sum3=sum1+sum2;
  printf("%d\n",sum3);
  printf("%d\n",and(sum1,sum2));
    printf("Final answer:%d\n",t3);
  return 0;
}





int and(int a,int b){
  int num,c=0,t,sum=0,j=1,k;
  t=num;
  num=a+b;
  while(num>0)
  {
    k=num%10;
    if(k==1) k=0;
    else if(k==2) k=1;
    else k=0;
    sum=sum+k*j;
    j=j*10;
    num/=10;
  }
  return sum;
}






int binary(int n){
  int t,sum=0,i=0,j=1;
  while(n>0){
      t=n%2;
      sum=sum+t*j;
      j*=10;
      n=n/2;
      i++;
  }
    return sum;
}
