/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-4
sec-4
Machine no-14
Question set - EVEN
Lab Test-2
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int p,b;
	FILE *f1;
	f1=fopen("t4e.txt","r");
	if(f1==NULL)
		exit(-1);
    fscanf(f1,"%d%d",&p,&b); // reading p and b
    float **a;
    int i, j;
    // dynamically allocating a 2d array
    a= (float **) calloc(p,sizeof (float *) );
    for (i=0;i<p;i++)
      a[i] = (float *) calloc(b,sizeof (float));

  // storing the values in 2d matrix
  for(i=0;i<p;i++){
    for(j=0;j<b;j++)
    fscanf(f1,"%f",&a[i][j]);
  }
	fclose(f1);


  printf("\n");
     for (i=0;i<p;i++)
      {
      for (j=0;j<b;j++)
        printf ("%f ", a[i][j]);
       printf ("\n");
     }

     int **a1;
     a1= (int **) calloc(p,sizeof (int *) );
     for (i=0;i<p;i++)
       a1[i] = (int *) calloc(b,sizeof (int));

  int sum=(3*b)/4+1;
  printf("#paintings= %d  #bidders= %d (3/4 = %d)\n",p,b,sum);
  printf("Top bids by the %d bidders:",b);
  float max;
  int *freq;
   freq= (int *) calloc(p,sizeof (int));

// forming another 2d matrix a1 for storing the top bid of a bidder
  for(j=0;j<b;j++){
    max=0;
    for(i=0;i<p;i++){
      if(a[i][j]>max){
        max=a[i][j];
      }
    }
    for(i=0;i<p;i++){
      if(max==a[i][j]){
        a1[i][j]=1;
      }
    }
  }
  printf("\n");
  // storing the frequency of each painting....
     for (j=0;j<b;j++)
      {
      for (i=0;i<p;i++){
        if(a1[i][j]==1){
          freq[i]++;
        printf("%d ",i+1);
      }
     }
  }
  int m=0,painting_no;
  for(i=0;i<p;i++){
    if(freq[i]>max)
      m=freq[i];
  }

  for(i=0;i<p;i++){
    if(m==freq[i]){
      painting_no=i+1; // storing the painting no
    }
  }

  // if top bid painting is greater than equal to 3/4 of bidders
  if(m>=sum){
    printf("\nBest painting is: %d",painting_no);
    printf("\nBidders with the best paintings as their top bid: ");
    // logic for printing the top bidders of the painting
    for (i=0;i<p;i++)
     {
     for (j=0;j<b;j++){
       if(a1[i][j]==1 && i==(painting_no-1))
       printf("%d ",j+1);
     }
    }
 }

  else
  printf("\nNo best paintings.\n");

	return 0;
}
