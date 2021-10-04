/*Problem statement : Create pascal's Triangle
1.Input : no of rows = 5
  Output :
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1

2.Input : no of rows = 3
  Output :
    1
   1 1
  1 2 1
*/

#include<bits/stdc++.h>
using namespace std;

void Pascal_tri(int no_rows)
{
  int i,j,k;
  int tmp=no_rows;
  for(i=0;i<no_rows;i++)
  {
    k=1;
    for(int k=tmp;k>=0;k--)
      cout<<" ";

     tmp--;

     for(j=0;j<=i;j++)
      {
        cout<<k<<" ";
        k=(k*(i-j)/(j+1));
      }
      cout<<endl;

  }
}

int main()
{
  int no_rows;
  cout<<"No of rows : ";
  cin>>no_rows;
  Pascal_tri(no_rows);
}
