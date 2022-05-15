package LeetCode;
/*
https://leetcode.com/problems/daily-temperatures/
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.
Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
*/


import java.util.Arrays;
import java.util.Stack;

public class DailyTemp {

    public static void main(String[] args) {
        int[] temp = {73,74,75,71,69,72,76,73};
        int[] ans = dailyTemperatures(temp);
        System.out.println(Arrays.toString(ans));
    }

    public static int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[temperatures.length];
        st.push(0);

        for(int i =1 ; i < temperatures.length ; i++){
            while (st.size() > 0  && temperatures[st.peek()] < temperatures[i]){
                ans[st.peek()] = i-st.peek();
                st.pop();

            }
            st.push(i);
        }

        while (st.size() !=0){
            ans[st.pop()] = 0;
        }

        return ans;

    }
}
