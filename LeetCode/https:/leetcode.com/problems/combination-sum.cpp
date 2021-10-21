// Link to the problem : https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result ;
        vector<int > sofar;
        backtrack(candidates, 0, target, sofar, result);
        return result;
    }
    
     void f(vector<int>& a, int idx, int T, vector<vector<int>>& gans, vector<int> sofar) {
        if ( idx >= a.size() || T < 0) {
            return;
        }

        if (T == 0) {
            gans.push_back(sofar);
            return;
        }
        
        // don't pick a[idx]
        f(a, idx+1, T, gans, sofar);
        
        // pick a[idx]
        sofar.push_back(a[idx]);
        f(a, idx, T-a[idx], gans, sofar);
    }
    
    void backtrack(vector<int>& candidates, int start, int target, vector<int > sofar, vector<vector<int>>& result){
        if(target<0) return ;
        
        if(target==0){
            cout << "sofar " << sofar.size() << endl;
            // vector<int> v;
            // v= sofar;
            result.push_back(sofar);
            return ;
        }
        
        for(int i=start;i<candidates.size();i++){
            sofar.push_back(candidates[i]);
            backtrack(candidates, i, target-candidates[i], sofar, result);
            sofar.pop_back();
        }
        
    }
};
