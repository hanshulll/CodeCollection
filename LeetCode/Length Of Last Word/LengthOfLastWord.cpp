#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s==" " || s == "") return 0;
        
        int i = s.length()-1;
        int first = i;
        while(i>=0){
            if(s[i] == ' '){
                first--;
            } else {
                break;
            }
            i--;
        }
        int second = first;
        while(i>=0){
            if(s[i] != ' '){
                second--;
            } else {
                break;
            }
            i--;
        }
        return first-second;
    }
};