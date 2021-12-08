package LeetCode;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

/*
Given a string s, remove duplicate letters so that every letter appears once and only once.
 You must make sure your result is the smallest in lexicographical order among all possible results.
 Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 */
public class RemoveDuplicateLetters {
    public static void main(String[] args) {
        String s = "cbacdcbc";

        System.out.println(removeDuplicateLetters(s));

    }
    public static String removeDuplicateLetters(String s) {
        char tempArray[] = s.toCharArray();
        Arrays.sort(tempArray);
        s =  new String(tempArray);

//        String ans = "";
//        Stack<Character> st = new Stack<>();
//        for(int i = 0 ; i<s.length() ; i++){
//            char ch = s.charAt(i);
//            if(st.size() == 0){
//                st.push(ch);
//                ans += ch;
//            }
//            if(st.peek() != ch){
//                st.push(ch);
//                ans+= ch;
//            }
//        }
//
//       return ans;
        Set<String> hash_Set = new HashSet<String>();
        for (int i = 0 ; i<s.length() ; i++){
            char ch = s.charAt(i);
            hash_Set.add(""+ch);
        }
        s = new String();
        return s;
    }
}

