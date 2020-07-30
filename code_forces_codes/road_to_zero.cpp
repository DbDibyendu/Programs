#include<bits/stdc++.h>
using namespace std;

#define MAX 100000000
#define deb(x) cout<< #x <<" : "<<x<<endl;
// int a[MAX];

void swap(long long int *a,long long int *b){
  long long int t=*a;
  *a=*b;
  *b=t;
}

int main()
{
  long long int t,n,i,j,k,sum,x,y,a,b;
  cin>>t;
    while(t--){
      sum=0;
      int sum2=0;
      int sum3=0;
      cin>>x>>y>>a>>b;
      // vector<int> v(n,0),prefix(n,0);
      if(x>y) swap(&x,&y); // y>x...
      if(x==0&&y==0) cout<<sum<<endl;
      else if(x!=0&&y==0){
        if(x>0) cout<<x*a<<endl;
        else
        cout<<-1*x*a<<endl;
      }
    else  if(y!=0&&x==0){
        if(y>0) cout<<y*a<<endl;
      }
      else if(x>0&&y>0){
        if(2*a>=b){
          sum=x*b+(y-x)*a;
        }
        else
          sum=(y+x)*a;
      cout<<sum<<endl;
    }
    else if(y>0&&x<0){
      sum=(y-x)*a;
      cout<<sum<<endl;
    }

    else if(x<0&&y<0){
      if(2*a>=b){
        sum=(-1)*y*b+ (y-x)*a;
      }
      else
       sum=-1*(x+y)*a;
      cout<<sum<<endl;
    }
    }
}
