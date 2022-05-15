#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    read:
    while(t--)
    {
        long long int a,b,cnet=0;
        cin>>a>>b;
        if(a%b==0)
        {
            cout<<"0\n";
            goto read;

        }
        while(a!=0)
        {
            if(a%b!=0)
            {
                a+=1;
                cnet++;
            }
            else
                break;
        }
        cout<<cnet<<endl;
    }
    return 0;
}
