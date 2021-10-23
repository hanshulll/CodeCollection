/*Question: Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
Example:
Input: height = [4,3,2,1,4]
Output: 16
*/

class Solution {
    public int maxArea(int[] height) {
        int maxwater=0, left=0, right=height.length-1;
        while(left<right)
        {
            maxwater = Math.max(maxwater, Math.min(height[left],height[right])*(right-left));//calculating max water stored
            if(height[left]<height[right])//Updating leftmost and rightmost barriers
                left++;
            else
                right--;
        }

        return maxwater;
    }
}
