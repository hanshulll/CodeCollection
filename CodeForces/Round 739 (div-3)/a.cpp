// https://codeforces.com/contest/1560/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    int t; cin>>t;
    vector<int> v;
    for(int i=1; i<=2500; i++){
        if(i%3!=0 && i%10!=3){
            v.push_back(i);
        }
    }
    cout << endl;
    while(t--){
        int x; cin>>x;
        cout << v[x-1] << endl;
    }
    return 0;
}