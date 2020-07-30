/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-2
sec-4
*/
#include <stdio.h>
#include <stdlib.h>
#define N 10

void transverse(int **p, int n)
{
    int swap;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap=p[i][j];
            p[i][j]=p[j][i];
            p[j][i]=swap;
        }
    }
    printf("the transpose is\n");
    for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        printf("%d ",p[i][j]);
	    }
	    printf("\n");
	}
}
float determinant(int **p,int n)
{
    float ratio,det;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j>i){
                ratio = p[j][i]/p[i][i];
                for(int k = 0; k < n; k++){
                    p[j][k] -= ratio * p[i][k];
                }
            }
        }
    }
    det = 1;
    for(int i = 0; i < n; i++)
        det *= p[i][i];
    return det;
}
int main() {

	printf("provide n:\n");
	int n,**p;
	scanf("%d",&n);
	p=(int**)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
	    p[i]=(int*)malloc(n*sizeof(int));
	}
	printf("provide numbers");
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        scanf("%d",&p[i][j]);
	    }
	}
	transverse(p,n);
	printf("the det is %.2f",determinant(p,n));
	return 0;
}
