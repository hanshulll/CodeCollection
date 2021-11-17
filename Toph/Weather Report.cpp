#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    char i='"';
    cin>>n;
    if(n>=70)
    {
        cout<<"Bad weather.\n";
    }
    else if(n<=30) cout<<"Good weather.\n";
    else cout<<i<<"Confusing weather."<<i<<endl;

    return 0;
}

