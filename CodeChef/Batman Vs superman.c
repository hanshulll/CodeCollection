#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;cin>>n;

    vector<int>v;
    while(n--){
       int t;
        cin>>t;
        if(t==1){
         int x; cin>>x;
         auto it=lower_bound(v.begin(),v.end(),x);
         v.insert(it,x);
        }
        else{
            if(v.size()<3){
                cout<<"Not enough enemies"<<endl;
                continue;
            }
            int s=v.size();
            s/=3;

            cout<<v[v.size()-s  ]<<endl;
        }
    }
	return 0;
}
