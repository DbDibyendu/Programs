/*
Sec 3
Pranit Mehnde
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to return minimum element
int min(int a,int b){
    if(a>b)return b;
    else
    return a;
}

// logic for forming the spiralmatrix
void spiralmatrix(int n,int a[1000][1000])
{
    int i,j;
   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;

            // Finds minimum of four values
            x = min(min(i, j), min(n-1-i, n-1-j));

            // For upper right half
            if (i <= j) {
                a[i][j]=(n-2*x)*(n-2*x) - (i-x) - (j-x);

            }

            // for lower left half
            else{
                 a[i][j]=(n-2*x-2)*(n-2*x-2) + (i-x)  + (j-x);

            }
        }
    }
}



int main()
{
  int n;
  int a[1000][1000]={0};
  printf("Enter n:");
  scanf("%d",&n);
  spiralmatrix(n,a);

// printing column wise
  for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
         printf("%d ",a[j][i]);
       }
    }
    return 0;
}
