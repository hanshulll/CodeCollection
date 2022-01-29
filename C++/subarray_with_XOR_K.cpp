#include<bits/stdc++.h>
using namespace std;
int find_subarr_XOR(int arr[], int n, int k){
    int cnt =0;
    int xorr = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        xorr = xorr ^ arr[i];
        if(xorr == k) cnt++;
        if(mp.find(xorr ^ k) != mp.end()){ //since y=xorr ^ k;
            cnt+= mp[xorr ^ k];
        }
        mp[xorr]++;
    }
    return cnt ;
}
int main(){
    int n, k;
    int arr[100];
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    int ans = find_subarr_XOR(arr,n,k);
    cout << ans << endl;
    return 0;
}