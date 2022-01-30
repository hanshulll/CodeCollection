class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        stack<char>st;
        for(int i=0;i<=s.length()-1;i++){
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty()){
            if(s[i]!=st.top()){
                return false;
            }
            st.pop();
            i++;
        }
        return true;
    }
};