class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (!intervals.size()) return {};

    sort(intervals.begin(), intervals.end());

    int right = 1;
    int lval = intervals[0][0];
    int rval = intervals[0][1];
    int n = intervals.size();
    vector<vector<int>> ans;

    while (right < n) {
        if (rval > intervals[right][1]) right++;
        else if (rval < intervals[right][0]) {
            ans.push_back({ lval,rval });
            lval = intervals[right][0];
            rval = intervals[right][1];
            right++;
        }
        else if (rval >= intervals[right][0] && rval <= intervals[right][1]) {
            rval = intervals[right][1];
            right++;
        }

    }
    ans.push_back({ lval,rval });
    return ans;
}
   
};