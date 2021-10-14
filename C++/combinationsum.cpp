/*
        Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> >ans;
    void solve(int index,int target,vector<int>arr,vector<int>temp){
        if(index==arr.size()){
            if(target==0)
                ans.push_back(temp);
            return;
            
        }
        
        if(arr[index]<=target){
            temp.push_back(arr[index]);
            solve(index,target-arr[index],arr,temp);
            temp.pop_back();
        }
        solve(index+1,target,arr,temp);
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        solve(0,target,candidates,temp);
        return ans;
        
        
    }
};

int main(){
    int t;
    cout<<"Enter number of testcase: ";
    cin>>t;
    cout<<endl;
    
    while(t--){
        int n;      
        cout<<"Enter size of array: " ;
        cin>>n;
        cout<<endl;
        vector<int> A;
         cout<<"Enter element of array: ";
        for(int i=0;i<n;i++){
            int x;
           
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cout<<"Target: ";
        cin>>sum;
        Solution ob;
        vector<vector<int> > result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
   		cout<<"Combination Sum are:";
        for(int i=0;i<result.size();i++){
            cout<<"(";
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}

/* Question link:  https://leetcode.com/problems/combination-sum/*/
