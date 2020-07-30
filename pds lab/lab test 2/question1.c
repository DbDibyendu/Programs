/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-1
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
  int n,c=0,i;
  printf("Enter n:" );
  scanf("%d",&n);

  // logic for finding the 3 numbers.....
  for(i=0;i<n/3;i=i+2){
    if((3*i+6)==n){
       c=1;    // keeping a counter if such a number is found
      printf("Answer: %d %d %d\n",i,i+2,i+4);
      break;
    }
  }
  // if such a combination is not possible c=0
  if(c==0){
    printf("No\n");
  }
  return 0;

}
