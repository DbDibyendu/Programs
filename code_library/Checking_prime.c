#include<stdio.h>
#include<stdlib.h>
int Isprime(int n)
{
  int i,a;
  if(n<=1)
  return 0;

    for(i=2;i<n;i++)
  {
    if(n%i==0)
      return 0;
  }
    return 1;


}
int main()
{
  int num1,num2,v=1;
  printf("Enter a: ");
  scanf("%d",&num1);
  printf("%d",Isprime(num1));
  printf("\nEnter b: ");
  scanf("%d",&num2);
  printf("%d\n",Isprime(num2));

  for(int i=num1;i<num2;i++)
  {
    if(Isprime(i)==1)
      if(v==1)
    {
        printf("%d",i);
        v++;
    }
      else
      printf(",%d",i);

  }
  return 0;

}
