#include<stdio.h>
void Print(char a[40],int n) {
   printf("\n{ ");
   int i;
   for(i=0;i<n;i++) {
      printf("%c ",a[i]);
   }
   printf("}");
}
void Helper(char sub[40],int i,int m,int n,int t){
  if(i==t) {
    Print(sub,i);
  }
  else{
    if(n){
    sub[i]='|';
    Helper(sub,i+1,m,n-1,t);
  } if(m){
    sub[i]='b';
    Helper(sub,i+1,m-1,n,t);
  }
  }
}



int main()
{
  int n,m;
  char a[50]={0};
  printf("Enter m:");
  scanf("%d",&m);
  printf("Enter n:");
  scanf("%d",&n);
  Helper(a,0,m,n-1,m+n-1);
  return 0;
}
