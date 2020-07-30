#include <stdio.h>
#include <stdlib.h>

int main()
{


    int a,b,x,y,p,q;
    int m,j;
    printf("Enter 3 pairs of numbers with increasing magnitude value\n");
    scanf("%d%d%d%d%d%d",&a,&b,&x,&y,&p,&q);
    m=(y-b)/(x-a);
    j=(q-y)/(p-x);
    if(m==j)
           printf("The points are collinear");

    else
            printf("The points are not collinear");
      return 0;
}
