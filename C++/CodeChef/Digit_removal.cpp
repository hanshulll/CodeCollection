#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll newD=n,rem,diff=0,c=0;
        while(newD>0){
           rem=newD%10;
           newD/=10;
           c++;
           if(rem==d){
               newD = newD*pow(10,c)+(rem+1)*pow(10,c-1);
               diff=newD-n;
               c=0;
           }
        }
        cout<<diff<<endl;
    }

    return 0;
}