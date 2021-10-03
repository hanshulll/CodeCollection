#include <iostream>

using namespace std;

int editDistance(string s, string t, int **ans){
    if(s.size() == 0 || t.size() == 0){
        return max(s.size(), t.size());
    }

    int m = s.size();
    int n = t.size();

    if(ans[m][n] != -1){
        return ans[m][n];
    }

    if(s[0] == t[0]){
        ans[m][n] = editDistance(s.substr(1), t.substr(1), ans);
        return ans[m][n];
    }

    int a = editDistance(s, t.substr(1), ans);
    int b = editDistance(s.substr(1), t, ans);
    int c = editDistance(s.substr(1), t.substr(1), ans);

    ans[m][n] = min(a, min(b,c)) + 1;
    return ans[m][n];    
}

int editDistanceDP(string s, string t){
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        ans[i] = new int[n + 1];
    }

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                ans[i][j] = max(i, j);
            }
            else if(s[i - 1] == t[j - 1]){
                ans[i][j] = ans[i - 1][j - 1];
            }
            else{
                ans[i][j] = min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i][j - 1])) + 1;
            }
        }
    }

    // for(int i = 0; i <= m; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return ans[m][n];
}

int main(){

    string s, t;
    cin>>s>>t;
    int ** ans = new int*[s.size() + 1];
    for(int i = 0; i <= s.size(); i++){
        ans[i] = new int[t.size() + 1];
        for(int j = 0; j <= t.size(); j++){
            ans[i][j] = -1;
        }
    }
    cout<<editDistanceDP(s, t)<<endl;

    return 0;
}