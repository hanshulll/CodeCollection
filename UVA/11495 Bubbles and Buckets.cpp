#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int cnet=0;
        int arr[10];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    cnet++;
                }
            }
        }
        if(cnet%2==0)
        {
            cout<<"Carlos\n";
        }
        else
        {
            cout<<"Marcelo\n";
        }
    }

    return 0;
}
