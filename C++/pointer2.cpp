#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m][k];
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < m; j++)
        {
            for (int u= 0; u < k; u++)
            {
                 cin>>a[i][j][u];
            }
        }
        
        

    }
    int (*p)[m][k]=a;
    cout<<*(*(*p+1)+2);
  
      

    return 0;
}