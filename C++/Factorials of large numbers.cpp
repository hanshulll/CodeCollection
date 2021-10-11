//Github username: hortiprajwal
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> ans;
        ans.push_back(1);
        int carry=0;
        for(int i=2;i<=N;i++){
            for(int j=ans.size()-1;j>=0;j--){
                int product=((ans[j]*i)+carry);
                carry=product/10;
                ans[j]=product%10;
            }
            if(carry==0){
                continue;
            }
            while(carry!=0){
                ans.insert(ans.begin(),carry%10);
                carry/=10;
            }
            carry=0;
        }
        return ans;
    }
};

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    Solution ob;
    vector<int> result=ob.factorial(n);
    for(int i=0;i<result.size();i++){
      cout<<result[i];
    }
    cout<<endl;
  }
  return 0;
}
