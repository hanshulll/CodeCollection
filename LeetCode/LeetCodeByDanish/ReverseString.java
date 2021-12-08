package LeetCode;

import java.util.Arrays;

/*
https://leetcode.com/problems/reverse-string/
Write a function that reverses a string. The input string is given as an array of characters s.
Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 */
public class ReverseString {
    public static void main(String[] args) {


       char[] s = {'h' , 'e', 'l' , 'l' , 'o'};
       reverseString(s);

        System.out.println(Arrays.toString(s));

    }

    public static void reverseString(char[] s)
    {
        func(s, 0, s.length-1);
    }

    public static void func(char[] s, int i, int j)
    {
        if(i>=j)return;
        char k = s[i];
        s[i] = s[j];
        s[j] = k;

        func(s, i+1, j-1);
    }



}
