#include<stdio.h>
#include<stdlib.h>
int factorial();
int power();
double expon();

int main()
{
  int num1,num2,num3;
  double num4;
  printf("Enter a number");
  scanf("%d",&num1);
  printf("%d\n", factorial(num1));
  printf("Write another number for power");
  scanf("%d",&num2 );
  printf("%d", power(num1,num2));
  printf("\nEnter the value for n : ");
  scanf("%d", &num3);

  printf("\nEnter the value for x : ");
  scanf("%f", &num4);
  printf("%f",expon(num3,num4) );
  return 0;
}

int factorial(int n)
{
  int sum=1;
  for(int i=1;i<=n;i++)
  {
    sum=sum*i;
  }
  return sum;
}
int power(int n,int k)
{
  int temp=n;
  for(int i=1;i<k;i++)
  {
   temp=temp*n;
  }
  return temp;
}
double expon(int k,double d)
{
  float sum=1,t=1;
  for(int i=1;i<=k;i++)
  {
      t=t*d/i;
      sum=sum+t;
  }
  return sum;
}
