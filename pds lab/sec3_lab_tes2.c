#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
int spiralmatrix(int n,int a[1000][1000])
{
  int i,k=0,l=0;
  int temp=n*n;
  while (k < n && l < n) {
      // the first row
      for (i = l; i < n; ++i) {
           a[k][i]=temp;
            temp--;
      }
      k++;
       // Print the last colunn from the remaining columns
      for (i = k; i < n; ++i) {
          printf("%d ", a[i][n - 1]);
      }
      n--;
       // Print the last row from the remaining rows
      if (k < n) {
          for (i = n - 1; i >= l; --i) {
              printf("%d ", a[n - 1][i]);
          }
          n--;
      }
      // Print the first column from the remaining columns
      if (l < n) {
          for (i = n - 1; i >= k; --i) {
              printf("%d ", a[i][l]);
          }
          l++;
      }
  }
  for(int j=0;j<n;j++){
    for(int j2=0;j2<n;j2++)
      printf("%d ",a[j][j2]);
      if(n%j==0)
      printf("\n" );
    }

}

*/

int main()
{
  int n,i,j;
  int a[1000][1000]={0};
  printf("Enter n:");
  scanf("%d",&n);
   int k=0,l=0;
  int n2=n;
  int temp=n*n;

  while (k < n && l < n) {
      // the first row
      for (i = l; i < n; ++i) {
           a[k][i]=temp--;
      }
      k++;
       // Print the last colunn from the remaining columns
      for (i = k; i < n; ++i) {
          a[i][n-1]=temp--;
        //   printf("%d ", a[i][n - 1]);
      }
      n--;
       // Print the last row from the remaining rows
      if (k < n) {
          for (i = n - 1; i >= l; --i) {
              a[n-1][i]=temp--;
            //   printf("%d ", a[n - 1][i]);
          }
          n--;
      }
      // Print the first column from the remaining columns
      if (l < n) {
          for (i = n - 1; i >= k; --i) {
              a[i][l]=temp--;
            //   printf("%d ", a[i][l]);
          }
          l++;
      }
  }
  n=n2;
  k=0,l=0;
   while (k < n && l < n) {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i) {
            printf("%d ", a[k][i]);
        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < n; ++i) {
            printf("%d ", a[i][n - 1]);
        }
        n--;

        /* Print the last row from the remaining rows */
        if (k < n) {
            for (i = n - 1; i >= l; --i) {
                printf("%d ", a[n - 1][i]);
            }
            n--;
        }

        /* Print the first column from the remaining columns */
        if (l < n) {
            for (i = n - 1; i >= k; --i) {
                printf("%d ", a[i][l]);
            }
            l++;
        }
    }


//   for (i = 0; i < n2; i++) {
//       for (j = 0; j < n2; j++) {
//         printf("%d ",a[j][i]);

//       }
//     }

  return 0;
}
