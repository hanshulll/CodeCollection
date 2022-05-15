   #include <bits/stdc++.h>
    using namespace std;

    int longestConsecutive(vector<int>& nums) {
        set <int> st;
        int largest_count = 0;
        //adding all elements to set
        for(auto x : nums){
            st.insert(x);
        }
        for(auto x : nums){
            //if one less than the curr vec element does not occur in set then do:
            if(!st.count(x-1)){
                int curr_num = x;
                int count = 1;
                //Counting all the consecutive > elements
                while(st.count(curr_num+1)){ 
                    count++;
                    curr_num++;
                }
                largest_count = max(largest_count, count);
            }
        }
        return largest_count;
    }
    int main(){
        int n;
        vector<int>nums;
        cin >> n;
        for(int i=0;i<n;i++){
            int val;
            cin >> val;
            nums.push_back(val);
        }
        int ans = longestConsecutive(nums);
        cout << ans << endl;
        return 0;
    }