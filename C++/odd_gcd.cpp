//Adarsh Priyadarshi
Question Link: https://www.codechef.com/START14C/problems/BININVER
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
void solve(){
    ll n;cin>>n;
    ll a[n];
    ll sum=0;
    ll c=0;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    if(sum%2!=0)cout<<0<<endl;
    else{
        for(ll i=0;i<n;i++){
            while(a[i]%2==0){
                a[i]=a[i]/2;
                c++;
            }
            v.push_back(c);
            c=0;
        }
        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }
    
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
