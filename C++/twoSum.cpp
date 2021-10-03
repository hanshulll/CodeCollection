/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> umap;
        int difference;

        for(int i = 0; i < nums.size(); i++ ){
            difference = target - nums.at(i);
            if(umap.find(difference) != umap.end()) {
                vector<int> v{umap[difference], i};
                return v;
            } else {
                umap[nums.at(i)] = i;
            }
        }

        return vector<int> {};
}
 
// Driver code
int main() {
    int n,target;
    cout << "Enter the size of vector/array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter vector/array elements: ";
    for(int i = 0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    

    for(int i=0;i<twoSum(nums,target).size();i++)
    {
        cout << twoSum(nums,target)[i] << " ";
    }
    cout << endl;
}

/*
    Test Case - 1: 

    Enter the size of vector/array: 4   
    Enter vector/array elements: 2 7 11 15
    Enter the target sum: 9
    Answer: 0 1 

    Test Case - 2: 

    Enter the size of vector/array: 3
    Enter vector/array elements: 3 2 4
    Enter the target sum: 6
    Answer: 1 2 

    Link to the problem: https://leetcode.com/problems/two-sum/
*/