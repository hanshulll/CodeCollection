// https://codeforces.com/contest/1560/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    int t; cin>>t;
    while(t--){
        ll k; cin>>k; // 14
        ll prev_sqrt = floor(sqrt(k)); //3
        if(prev_sqrt*prev_sqrt == k){
            prev_sqrt -= 1;
        }
        ll prev_sq = prev_sqrt*prev_sqrt; //9

        ll excess = k-prev_sq; //5
        ll x, y;
        if(excess<=prev_sqrt){
            x = excess;
            y = prev_sqrt + 1;
        } else {
            x = prev_sqrt + 1; // 4
            ll excess1 = excess - x; // 1
            y = prev_sqrt + 1 - excess1; // 4-1=3
            // cout << prev_sq << " " << excess << " " << excess1 << endl;
        }
        
        cout << x << " " << y << endl;
    }
}