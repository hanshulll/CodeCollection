#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0 ; i < t ; i++){
        int n ;
        cin>>n;
        vector<int>v(n);
        for(int i=0 ; i < n ; i++){
            cin>>v[i];
        }
           if( v[0] < v[n-1]){
               cout<<"Yes"<<endl;
           }
           else{
               cout<<"No"<<endl;
           }
    }
    return 0;
}