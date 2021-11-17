#include<bits/stdc++.h>
using namespace std;
                 //Welcome To Hridoy's Code
#define   ll                  long long
#define   ull                 unsigned long long
#define   pb                  push_back
#define   em                  emplace_back
#define   ff                  first
#define   ss                  second
#define   endl                "\n"
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;

int T, Q;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int c = 0; c < T; c ++) {
        string text;
        cin >> text;
        cin >> Q;
        set<pair<int, int>> ranges;
        int lastID = 0;
        for (int i = 0; i < int(text.size()); i ++) {
            if (text[i] != text[lastID]) {
                ranges.insert(make_pair(lastID, i - 1));
                lastID = i;
            }
        }
        ranges.insert(make_pair(lastID, int(text.size()) - 1));
        
        cout << "Case " << c + 1 << ":" << endl;
        while (Q --) {
            int type, position;
            cin >> type >> position;
            if (type == 1) {
                auto it = --ranges.upper_bound(make_pair(position,  1 << 30));
                cout << ((*it).second - (*it).first + 1) << endl;
            } else {
                auto it = --ranges.upper_bound(make_pair(position, 1 << 30));
                int l = (*it).first, r = (*it).second;
                ranges.erase(it);
                if (l != position) ranges.insert(make_pair(l, position - 1));
                if (r != position) ranges.insert(make_pair(position + 1, r));
            }
        }
    }
    
    return 0;
}
	