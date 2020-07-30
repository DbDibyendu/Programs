#include <stdio.h>
#include<math.h>

int main()
{
    int a[100]={0},i,j,no,t,k,number,number2,sum;
    printf("Enter a number:");
    scanf("%d",&number);
    printf("Enter the summation of binary digits:");
    scanf("%d",&number2);
    no=pow(2,number);
    for(j=0;j<no;j++)
    {
      sum=0;
      i=0;
      t=j;
      while(t!=0){
        a[i]=t%2;
        t=t/2;
        i++;
    }
    for(k=number-1;k>=0;k--)
    {
      sum+=a[k];
    }
    if(sum==number2){
        printf("\n");
        for(k=number-1;k>=0;k--){
          printf("%d",a[k]);
          }
      }
  }

    return 0;
}
