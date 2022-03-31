class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum_candies = candies[0];
        for(auto i:candies){
            maximum_candies = max(maximum_candies, i);
        }
        vector<bool> v;
        for(int i=0;i<candies.size();i++){
            int sum = extraCandies + candies[i];
            if(sum>=maximum_candies){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }
        return v;
    }
};