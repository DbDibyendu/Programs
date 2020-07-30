#include<stdio.h>
#include<math.h>

int main(){
  long int n,a[100000],t;
  scanf("%d",&t);
  while(t){
    scanf("%d",&n);
    int prefix=-1,suffix=n;
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
      if(i>a[i]){
        break;
      }
      prefix=i;
    }
    for(int i=n-1;i>=0;i--){
      if(n-1-i>a[i]){
        break;
      }
        suffix=i;
    }
    if(prefix>=suffix) printf("Yes\n");
    else
    printf("No\n");
    t--;
  }

  return 0;
}
