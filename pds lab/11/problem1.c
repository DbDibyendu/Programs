/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-1
sec-4
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[10][10],b[10][10],c[10][10], r1, c1, r2, c2;
    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Taking input until columns of the first matrix is equal to the rows of the second matrix
    while (c1 != r2) {
        printf("Error! Enter rows and columns again.\n");
        printf("Enter rows and columns for the first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for the second matrix: ");
        scanf("%d%d", &r2, &c2);
      }

    printf("\nEnter elements of matrix 1:\n");

    for (int i=0;i<r1;++i) {
        for (int j=0;j<c1;++j) {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter elements of matrix 2:\n");

    for (int i=0;i<r2;++i) {
      for (int j=0;j<c2;++j) {
              scanf("%d",&b[i][j]);
        }
    }

    // Initializing elements of matrix c to 0
    for (int i=0;i<r1;++i) {
        for (int j=0;j<c2;++j) {
            c[i][j]=0;
        }
    }

    // Multiplying first and second matrices and storing in c
    for (int i=0;i<r1;++i) {
        for (int j=0;j<c2;++j) {
            for (int k=0;k<c1;++k) {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }


    printf("\nOutput Matrix:\n");
    for (int i=0;i<r1;++i) {
        for (int j=0;j<c2;++j) {
            printf("%d  ",c[i][j]);
            if (j==c2-1)
                printf("\n");
        }
    }
    return 0;
}
