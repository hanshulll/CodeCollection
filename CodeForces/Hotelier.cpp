#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10]={0}, i,n;
    string s;
    cin>>n>>s;
    for(i=0; i<n; i++)
    {
        if(s[i]=='L')
        {
            for(i=0; i<10; i++)
            {
                if(arr[i]==0)
                {
                    arr[i]=1;
                    break;
                }
            }
        }
        else if(s[i]=='R')
        {
            for(i=9; i>=0; i--)
            {
                if(arr[i]==0)
                {
                    arr[i]=1;
                    break;
                }
            }
        }
    }
    for(i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
