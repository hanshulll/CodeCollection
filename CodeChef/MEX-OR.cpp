//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int powerOf2(int n){
    int count=1;
    int power=0;
    while (count<=n)
    {
        count*=2;
        power++;
    }
    return count;
}
int power2(int n){
    int count=1;
    int power=0;
    while (count<=n)
    {
        count*=2;
        power++;
    }
    return power-1;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
    int x;
    cin>>x;
    int ans =power2(x);
    if (x>=((1<<ans)-1) && x<=(1<<(ans+1))-2)
    {
        cout<<(1<<ans)<<endl;
    }else
    {
        cout<<(1<<(ans+1))<<endl;
    }
    }
    
    return 0;
}
