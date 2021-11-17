#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n,cnet=0;
   cin>>n;

   while(n!=0)
   {
       if(n>=100)
       {
           n-=100;
          // cnet++;
       }
       else if(n>=20)
       {
           n-=20;
          // cnet++;
       }
       else if(n>=10)
       {
           n-=10;
          // cnet++;
       }
       else if(n>=5)
       {
           n-=5;
          // cnet++;
       }
       else if(n>=1)
       {
           n-=1;
          // cnet++;
       }
       cnet++;
   }

    cout<<cnet<<endl;
}
