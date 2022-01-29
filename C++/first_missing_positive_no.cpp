#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int p=nums.size();
        int a[p+1];
        for(int i=0;i<=p;i++)
            a[i]=0;
        for(int i=0;i<p;i++){
            if(nums[i]>0 && nums[i]<=p){
                a[nums[i]]=1;
            }
        }
        for(int i=1;i<=p;i++){
            if(!a[i])
                return i;
        }
        return (p+1);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    Solution obj;
    int missing = obj.firstMissingPositive(arr);
    cout << "The smallest positive missing number is " << missing;
    return 0;
}
