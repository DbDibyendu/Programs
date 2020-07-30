#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float result();

int main()
{
  float x,n,s=0;
  for(int i=1;i<1040;i++){
  s+=result(1/i,2);
  }
  printf("S1:%3.2f\n",s);
  return 0;
}
float result(int x,int n)
{
  return ((pow(10,n)*x+(0.5))/(pow(10,n)));
}
