/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-3
sec-4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_data (int **p, int h)
  {
     int i, j;
      for (i=0;i<h;i++)
      {
      for (j=0;j<h;j++)
        printf ("%5d ", p[i][j]);
       printf ("\n");
      }
}

int main(){
  int n;
  printf("Enter N:");
  scanf("%d",&n);
  int **a,**b;
  int i,j,t,k;

  a = (int **) calloc(n,sizeof (int *) );
   for (i=0;i<n;i++)
      a[i] = (int *) calloc(n,sizeof (int));

  b = (int **) calloc(n,sizeof (int *) );
   for (i=0;i<n;i++)
      b[i] = (int *) calloc(n,sizeof (int));


  for(j=0;j<n-1;j++){
    printf("\nFriends of %d:",j);

    // logic for filling array a
    for(i=0;i<n-j-1;i++){
      scanf("%d",&t);
      if(t==-1) break;
      else if(t>0){
        a[t][j]=1;
      }
    }
  }

  // all a[i][i] elements will be 1
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j) a[i][j]=1;
      if(a[i][j]==1) a[j][i]=1;
    }
  }

  for (i=0;i<n;i++)
  {
  for (j=0;j<n;j++)
    printf ("%d ", a[i][j]);
   printf ("\n");
  }
  // logic for filling array B
  for(i=0;i<n/2;i++){
    for(j=0;j<n;j++){
      if(i!=j){
      if(a[i][j]==1){
        for(k=0;k<n;k++){
          if(a[k][j]==1) b[i][k]=1; b[k][i]=1;
        }
      }
    }

  }
}

printf("\n\n");
    for (i=0;i<n;i++)
    {
      for (j=0;j<n;j++){
        if(i==j) b[i][j]=1;
      printf ("%d ", b[i][j]);
    }
      printf ("\n");
    }
    int max=0,count;

    //logic for finding best student
    for(i=0;i<n;i++){
      count=0;
      for(j=0;j<n;j++){
        if(b[i][j]==1) count++;
      }
      if(count>max){
        max=count;
      }
    }


    printf("\nBest students are: ");
    for(i=0;i<n;i++){
      count=0;
      for(j=0;j<n;j++){
        if(b[i][j]==1) count++;
      }
        if(count==max)
          printf("%d,",i);
    }
}
