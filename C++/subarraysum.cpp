#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
    int n,m;cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deque<int> q;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum<m){
            q.push_back(i);
            sum +=a[i];
            }
        while(sum>m){
            int x=q.front();
            q.pop_front();
            sum-=a[x];
        }
        if(sum==m){
            break;
        }
    }
    if(q.empty() || sum!=m){
        cout<<-1<<endl;
    }
    else{
        cout<<q.front()+1<<" "<<q.back()+1<<endl;
    }
    }
    return 0;
}