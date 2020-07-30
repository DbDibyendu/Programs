#include <stdio.h>
#include<math.h>

int main()
{
    int a[100]={0},no,b[100]={0},c[50]={0},i=0,j,sum,t=1;
    printf("Enter a number less than 3 digit:");
    scanf("%d",&no);
    while(no!=0){
        a[i]=no%2;
        no=no/2;
        i++;
    }
    for(j=i-1;j>=0;j--){
    printf("%d",a[j]);
    }
    printf("\n");
    for(int k=0;k<=i;k++){
    b[k]=a[k+1];
    }
    b[i-1]=a[0];
     for(j=i-1;j>=0;j--){
    printf("%d",b[j]);
    }
    printf("\n");
     for(j=0;j<i;j++){
         c[j]+=a[j]+b[j];
         if((c[j]!=0)&&(c[j]!=1)){
           c[j]=1;
         c[j+1]+=1;
         }
    }
    for(j=i;j>=0;j--){
    printf("%d",c[j]);
    }
     for(j=0;j<=i;j++){
    t=pow(2,j);
    sum=sum+c[j]*t;
    }
    printf("\nConverted back to decimal:%d",sum);
    return 0;
}
