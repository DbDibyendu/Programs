#include<stdio.h>

int main()
{
  int a[100],no,j,i,b;
  printf("\t\t1ST GAME\nFirst one to print 21 loses\nEnter 0 to terminate the input of numbers\n");
  for(j=1;j<=5;j++)
{
  printf("Now enter the numbers:");
  for(i=1;i<=4;i++)
  {
    scanf("%d",&a[i]);
    if(a[i]==0)
    {
      break;
    }
  }
  for(int k=a[i-1]+1;k<=4*j;k++)
  {
    printf("%d ",k);
  }
  printf("\n");
}
  printf("\nNow enter the numbers:\n");
  scanf("%d",&b);
  if(b=21)
    printf("You lose\n");

  return 0;

}
