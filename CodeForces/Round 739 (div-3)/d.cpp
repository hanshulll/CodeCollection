// https://codeforces.com/contest/1560/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

vector<string> power_of_2;

ll solve(string f, string t){
    ll i=0, j=0, similar=0;
    while(i<f.length() && j<t.length()){
        if(f[i] == t[j]){
            similar += 1;
            i+=1; j+=1;
        } else {
            i+=1;
        }
    }
    return ((int)f.size()-similar + (int)t.size()-similar);
}

int main(){
    int t; cin>>t;
    for(ll i=1; i<=2e18; i*=2){
        power_of_2.push_back(to_string(i));
    }
    while(t--){
        string n; cin>>n;
        ll ans = n.length()+1;
        for(auto power : power_of_2){
            ans = min(ans, solve(n, power));
        }
        cout << ans << endl;
    }
    return 0;
}