#include <bits/stdc++.h>
using namespace std;
#define int long long
int binaryexponentiation(int x,int n,int m){
    int res=1;
    while(n!=0){
        if(n%2==1){
            res=((__int128)res*x)%m;
        }
        x=((__int128)x*x)%m;
        n/=2;
    }
    return res;
}
int32_t main(){
    int m=1e9+7;
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int mod=m;
        if(a!=b){
            mod=abs(a-b);
        }
        int s=(binaryexponentiation(a,n,mod)+binaryexponentiation(b,n,mod))%(mod);
        int gcd=(__gcd(s,abs(a-b)))%m;
        cout<<gcd<<endl;
    }
}
