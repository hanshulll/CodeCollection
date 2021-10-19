#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<ll>tree[200001];
ll ans[200001];
void solve(int cu , int par  ){
   ll sub=0;
   for(auto ch : tree[cu]){
     if(ch !=par){
       solve(ch,cu);
       sub+=(1+ans[ch]);
     }
   }
   ans[cu]=sub;
}
 
int main()
{  
    ll n,x ;
    cin>>n;
    for(ll i = 2 ; i<=n ;i++){
      cin>>x;
      tree[x].push_back(i);
      tree[i].push_back(x);
    }
    solve(1,-1);
    for(ll i = 1; i<=n ; i++){
      cout<<ans[i]<<" ";
    }
    return 0;
}