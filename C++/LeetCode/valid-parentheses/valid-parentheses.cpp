class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty() or st.top()!='(')
                    return false;
                st.pop();
            }
            else if(s[i]=='{')
                st.push(s[i]);
            else if(s[i]=='}'){
                if(st.empty() or st.top()!='{')
                    return false;
                st.pop();
            }
            else if(s[i]=='[')
                st.push(s[i]);
            else if(s[i]==']'){
                if(st.empty() or st.top()!='[')
                    return false;
                st.pop();
            }
        }
        return st.empty();       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // stack<char>st;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='(' or s[i] == '{' or s[i] == '[')
        //         st.push(s[i]);
        // }
        // for(int i=s.length()-1;i>=0;i--){
        //     if(s[i]==')' and s[i-1] == '('){
        //         while(!st.empty() and st.top()!='('){
        //             st.pop();
        //         }
        //         st.pop();
        //     }
        //     else if(s[i]=='}' and s[i-1] == '{'){
        //         while(!st.empty() and st.top()!='{'){
        //             st.pop();
        //         }
        //         st.pop();
        //     }
        //     else if(s[i]==']' and s[i-1] == '['){
        //         while(!st.empty() and st.top()!='['){
        //             st.pop();
        //         }
        //         st.pop();
        //     }
        // }
        // if(st.empty()){
        //     return true;
        // }
        // else
        //     return false;
    }
};