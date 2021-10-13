// https://codeforces.com/contest/1560/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int cntsrc[26];
int* cnt = cntsrc - 'a';

pair<string,string> decrypt(string s){
    reverse(s.begin(), s.end());
    string order;

    for(auto c : s){
        if(!cnt[c]) order.push_back(c);
        cnt[c]+=1;
    }

    int order_len = order.length();
    int original_length = 0;

    for(int i=0; i<order_len; i++){
        original_length += (cnt[order[i]]/(order_len-i));
    }

    reverse(order.begin(), order.end());
    return {string(s.rbegin(), s.rbegin()+original_length), order};

}

string encrypt(pair<string,string> s){
    string res = s.first;
    for(auto c : s.second){
        string temp;
        for(auto d : s.first){
            if(d!=c){
                temp.push_back(d);
                res.push_back(d);
            }
        }
        s.first = temp;
    }
    return res;
}

int main(){
    int test; cin>>test;
    while(test--){
        memset(cntsrc, 0, sizeof(cntsrc));
        string t; cin>>t;
        auto s = decrypt(t);
        auto expected_t = encrypt(s);
        if(t == expected_t) cout << s.first << " " << s.second << endl;
        else cout << -1 << endl;
    }
    return 0;
}