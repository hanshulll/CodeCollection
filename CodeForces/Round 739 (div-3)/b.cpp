// https://codeforces.com/contest/1560/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    int t; cin>>t;
    while(t--){
        ll a,b,c, A, B;
        cin>>A>>B>>c;
        if(B<A) swap(A,B);
        ll to_one = (A==1)?0:A-1;
        ll diameter = B-A;
        ll circum = 2*diameter;
        if((to_one >= diameter) || (c>circum) || (B-A == 1)) cout << -1 << endl;
        else {
            ll ans;
            if(c<=diameter) ans = c+diameter;
            else ans = c-diameter;
            if((ans>=1) && (ans<=circum) && (ans!=A) && (ans!=B) && (ans!=c)) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}