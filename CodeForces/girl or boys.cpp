#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string>str;
    vector<string>str2;
    cin>>str;
    int s=str.size();
    for(int i=0;i<s;i++)
    {
        if(!str[i])
        {
            str2=str[i];
        }
    }
    cout<<str2<<endl;
    return 0;
}
