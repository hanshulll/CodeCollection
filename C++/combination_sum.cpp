class Solution {
public:
    vector<vector<int>> ans;
    
    void allc(vector<int>& cd,vector<int>& cur,int st,int tg){
        if(tg<0)return;
        if(tg==0){ans.push_back(cur);return;}
        for(int i = st ; i<cd.size() ; i++){
            cur.push_back(cd[i]);
            allc(cd,cur,i,tg-cd[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cd, int tg) {
        vector<int> cur;
        allc(cd,cur,0,tg);
        return ans;
    }
};
