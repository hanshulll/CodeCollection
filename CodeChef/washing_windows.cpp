#define fio                          \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define M 1000000007

signed main() {
    fio;
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        int w[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>w[i][j];
                if(i==0) cout<<'1';
                else {
                    int a = (j-1==-1)?INT_MIN:w[i-1][j-1];
                    int b = w[i-1][j];
                    int c = (j+1==m)?INT_MIN:w[i-1][j+1];
                    if(w[i][j]>a and w[i][j]>b and w[i][j]>c)
                        cout<<'1';
                    else cout<<'0';
                    w[i][j]=max(w[i][j], a);
                    w[i][j]=max(w[i][j], b);
                    w[i][j]=max(w[i][j], c);
                }
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
}
