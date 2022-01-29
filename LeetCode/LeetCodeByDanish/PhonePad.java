package LeetCode;

import java.security.PublicKey;
import java.util.ArrayList;

/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 */
public class PhonePad {
    public static void main(String[] args) {
        String str = "23";
        ArrayList<String> st = GetPhonePad(str);

    }
    static ArrayList<String> GetPhonePad(String str){
        if(str.length() == 0){
            ArrayList<String> s = new ArrayList<>();
            s.add("");
            return s;
        }
        int ch = str.charAt(0);
        String ros = str.substring(1);

        ArrayList<String> mr = GetPhonePad(ros);

     return  mr;
    }
}
