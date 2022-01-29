/*
Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        unordered_map<char,int> m;//HashMap to store the frequencies of all the characters present in string 'p'.

        for(int i=0;i<p.length();i++)
            m[p[i]]++;

        int count=m.size();//count variable to check when all the characters present in the map have frequencies zero,which implies that an anagram is found.

        int k=p.length();//Window size.
        int i=0;
        int j=0;
        while(j<s.length())
        {
            if(m.find(s[j])!=m.end())//if a character is found which is present in the map then decrease it's frequency by 1.
            {
                m[s[j]]--;
                if(m[s[j]]==0)//if the frequency of a particular character in the map is zero it implies that all the occurences of that particular character is found in the current window size.
                    count--;
            }
            if(j-i+1 < k)
                j++;
            else if(j-i+1==k)
            {
                if(count==0)//if the count is equal is zero it means that an anagram is found.
                    res.push_back(i);//if an anargram is found then push the starting index of the window.

                if(m.find(s[i])!=m.end())//while sliding the window check if that character is present in the map then increase it's frequency by one as we have decreased the frequency of that character when it was first encountered while traversing the window.
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};