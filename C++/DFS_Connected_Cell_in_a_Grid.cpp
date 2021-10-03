// Problem statement - https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs
#include <bits/stdc++.h>
using namespace std;
int a[10][10];

int count(int i,int j,int n, int m){
    int an=0;
    if(i<0 || j<0 || i>=n || j>= m){
        return 0;
    }
    if(a[i][j]==0){
        return 0;
    }
    else{
        an++;
        a[i][j]--;
    }
    
    for(int x=i-1;x<i+2;x++){
        for(int y=j-1;y<j+2;y++){
            if(x!=i || y!=j){
                an+=count(x,y,n,m);
            }
        }
    }
    
    return an;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    int max=-1,ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                ans = count(i,j,n,m);
                if(max<ans){
                    max=ans;
                }
            }
        }
    }
    cout<<max;
    
    
    return 0;
}

