#include <iostream>
using namespace std;

int main()
{

int c,w,i,j;
    int a[100][100],b[100][100],sum[100][100]={0},res[100][100]={0};
    cin >> c;




    for(i = 0; i < c; ++i)
       for(j = 0; j < c; ++j)
       {
           cin >> a[i][j];
       }

    for(i = 0; i < c; ++i)
       for(j = 0; j < c; ++j)
       {
           cin >> b[i][j];
       }
       cin>>w;

    // Adding Two matrices
    for(i = 0; i < c; ++i)
        for(j = 0; j < c; ++j){
            sum[i][j] = a[i][j] - b[i][j];
            sum[i][j] = sum[i][j]*sum[i][j];
          }

            for(i=0;i<c;i++)
              for(j=0;j<c;j++){
                for(int l=0;l<w;l++)
                  for(int m=0;m<w;m++)
                res[i][j]+=sum[i+l][j+m];
            }


                  for(i = 0; i < c; ++i)
                      for(j = 0; j < c; ++j)
                      {
                          cout << res[i][j] << " ";
                          if(j == c - 1)
                              cout << endl;
                      }


    return 0;
}
