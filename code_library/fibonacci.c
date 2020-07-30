#include <stdio.h>
int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    //return 0;
    printf("\nFibonacci from function:\n" );
    for(i=1;i<=n;i++){
      printf("%d, ",Fibonacci(i));
    }
}

int Fibonacci(int n){
  if(n==1)
  return 0;
  else if(n==2)
  return 1;
  else
  return Fibonacci(n-1)+Fibonacci(n-2);
}
