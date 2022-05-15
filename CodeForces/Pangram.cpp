#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,n;
    cin>>n;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    sort(s.begin(),s.end());
    int cnet=0;
    for(i=0;i<n;i++)
    {
        if(s[i]!=s[i+1])
        {
            cnet++;
        }
    }
    if(cnet==26)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

    return 0;
}
