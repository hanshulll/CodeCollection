#include <bits/stdc++.h>
using namespace std;

#define int             long long int
#define mp make_pair
#define ff first
#define ss second
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PT 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
int32_t main() {

   int x; 
   cin >> x;
   while(x--) {
      int n, m;
      cin >> n >> m;
      
      int a[m];
      for (int i = 0; i < m; i++){
          cin >> a[i];
      }
      vector<int>st;
      st.push_back(a[0]);

      int final_ans = 0;
      for (int i = 0; i < m; i++) {
         if (i == 0) continue;
         int k = 0;
         for (int j = 0; j <st.size(); j++){
            if (st[j] < a[i]) {
                k++;}
                else{}
         }
         st.push_back(a[i]);
         final_ans += k;
      }

      cout << final_ans << endl;
   }


   cout.clear();
   cin.clear();
   return 0;
}