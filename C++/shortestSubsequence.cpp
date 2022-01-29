#include <iostream>
#include <climits>

using namespace std;

int shortestSubsequence(string s, string t, int m, int n, int **ans){
    if(m <= 0){
        return 1005;
    }
    if(n <= 0){
        return 1;
    }

    if(ans[m][n] != -1){
        return ans[m][n];
    }

    int i;
    for(i = 0; i < n; i++){
        if(t[i] == s[0]){
            break;
        }
    }

    if(i == n){
        ans[m][n] = 1;
        return ans[m][n];
    }

    ans[m][n] = min(shortestSubsequence(s.substr(1), t, m - 1, n, ans), 1 + shortestSubsequence(s.substr(1), t.substr(i), m - 1, n - i - 1, ans));

    return ans[m][n];

}

int shortestSubsequenceDP(string s, string t){
    int m = s.size();
    int n = t.size();

    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        ans[i] = new int[n + 1];
    }

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0){
                ans[i][j] = 1;
            }
            else if(i == 0){
                ans[i][j] = 1005;
            }
            else{
                int k;
                for(k = j - 1; k > -1; k--){
                    if(t[k] == s[i - 1]){
                        break;
                    }
                }
                if(k == -1){
                    // cout<<i<<" "<<j<<" "<<ans[i-1][j]<<" "<<ans[i-1][k] + 1<<endl;
                    ans[i][j] = 1;
                }
                else{
                    // cout<<i<<" "<<j<<" "<<ans[i-1][j]<<" "<<ans[i-1][k] + 1<<endl;
                    ans[i][j] = min(ans[i - 1][j], ans[i - 1][k] + 1);
                }
            }
        }
    }

    // for(int i = 0; i <= m; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout<<ans[i][j]<<" ";
    //     }

    //     cout<<"\n";
    // }

    if(ans[m][n] >= 1005){
        ans[m][n] = -1;
    }

    return ans[m][n];
}

int main(){

    string s,t;cin>>s>>t;
    int m = s.size();
    int n = t.size();

    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++){
            ans[i][j] = -1;
        }
    }

    cout<<shortestSubsequenceDP(s, t)<<endl;
    

    return 0;
}