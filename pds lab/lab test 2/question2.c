/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-2
sec-4
Machine no-14
Question set - EVEN
Lab Test-2
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int ans=0;

// finding the correct numbers
int find(long temp, int check)
{
 int r;
 int sum = 0;
  while(temp>0)
  {
      r= temp%10;
      sum+=r;
      temp=temp/10;
  }
  if(sum <= check)
      return 1;
  return 0;
}

// logic for generating the pattern
void generate_pattern(long temp, int c, int d, int check, int digit)
{
  if(digit == 0)
      {
          if (find(temp, check))
          {
              printf("%d\n", temp);
          }
          return;
      }
  else
  {
      long temp1=temp;
      temp1=temp1*10+c;
      generate_pattern(temp1,c,d,check,digit-1);
      temp=temp*10+d;
      generate_pattern(temp,c,d,check,digit-1);
  }
}

int main() {
  int c,d;
  printf("Enter 2 numbers:");
  scanf("%d%d",&c,&d);
  int check=4*c+d+5;
  // using reccursive function to print the required output
  generate_pattern(0,c,d,check,6);
  return 0;
}
