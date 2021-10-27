class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int target)
    {

        vector<int> ans;

        int n = a.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            if (m.find(target - a[i]) != m.end())
            {
                ans.push_back(i);
                ans.push_back(m[target - a[i]]);
                break;
            }

            m[a[i]] = i;
        }
        return ans;
    }
};