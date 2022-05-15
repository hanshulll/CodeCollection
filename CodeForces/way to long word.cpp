#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>str;
        int n=str.size();
        if(n>10)
        {
            cout<<str[0];
            cout<<n-2;
            cout<<str[n-1]<<endl;
        }
        else
        {
            cout<<str<<endl;
        }
    }
    return 0;
}

