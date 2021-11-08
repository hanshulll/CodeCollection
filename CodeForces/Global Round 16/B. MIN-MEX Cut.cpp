#include <bits/stdc++.h>
using namespace std;
int main() {
int x;
cin >> x;
while(x--) {
      string str;
      cin >> str;
      int mex = 0, sum = 0;
      for (int i = 0; i < str.size();i++) {
         if (str[i] == '0') {
             mex= 1;
         }
         else if (mex== 1 and str[i] != '0') {
            sum++; 
            mex = 0;
         }
      }if (str[str.size() - 1] == '0') {
          sum++;
      }else{}
      
      cout << min(sum, 2) << endl;
}   return 0;
}