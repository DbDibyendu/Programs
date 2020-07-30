#include<bits/stdc++.h>
#include<string>
using namespace std;

#define MAX 100000000
#define deb(x) cout<< #x <<" : "<<x<<endl;
// int a[MAX];

void swap(long long int *a,long long int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

int main()
{
  int t,n,i,j,k,sum,x,y,a,b;
  cin>>t;
    while(t--){
      string s;
      cin>>s;
      n=s.size();
      j=1,k=0;
      char cmp;
      for(i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
              k=1;
              break;
            }
        }
        if(k==1){
          for(i=0;i<n;i++)
              cout<<"10";
        }
        else
          cout<<s;
        cout<<endl;
    }
}
