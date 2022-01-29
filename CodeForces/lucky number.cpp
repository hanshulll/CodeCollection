#include<iostream>

using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    int luck=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='4' || str[i]=='7')luck++;
    }
    if(luck==4 || luck==7)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
