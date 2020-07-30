#include<stdio.h>
int function();
int main()
{
  int A[5],n,i;
  for(int i=0;i<5;i++)
{
  printf("Enter number %d:",i);
  scanf("%d",&A[i]);
}
printf("Enter a number:\n");
scanf("%d",&n);
function(A,n);
  return 0;
}

int function(int B[],int n)
{
  int sum=0,k,z=0,t=0;

    for(int j=0;j<(2*2*2*2*2);j++)
  {
      sum=0;
      z=0;
      int it=j;
      while(it>0)
      {
          k=it%2;
          if(k==1)
        {
          sum=sum+B[z];

        }
          it/=2;
          z++;
      }

      if(sum==n)
      {
       t=t+1;
      }
    }
    printf("%d\n",t);
    if(t!=0)
    printf("Yes\n");
    else
    printf("No\n");
}
