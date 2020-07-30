/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-2
sec-4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
  char *s1,*s2,*s3;
  int m,n,i,j,count,k;
  printf("Enter m and n(m less than n):");
  scanf("%d%d",&m,&n);
  s1=(char *)malloc(m*sizeof(char));
  s2=(char *)malloc(n*sizeof(char));
  int max=0;
  printf("Enter S and T:");
  scanf("%s%s",s1,s2);
  for(i=0;i<n-m+1;i++){
    count=0;
      for(j=i;j<m+i;j++){
        if(s1[j-i]==s2[j]){
          count++;
        }
      }

      if(count==m) {
        printf("Yes\n");
        break;
      }
      else if(count>max){
        max=count;
        k=i; // getting the index of most similar pattern
      }
  }

  if(count<m){
  printf("Best match:");
  for(i=k;i<k+m;i++){
    printf("%c",s2[i]);
  }
  printf(" (Difference: %d)",m-max);
}
    return 0;
}
