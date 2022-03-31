// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        string a="";
        for(int i=0;i<S.length();i++){
            if(S[i]!='.')
                a += S[i];
            if(S[i] == '.' or i == S.length()-1){
                st.push(a);
                a="";
            }
        }
        S = "";
        while(!st.empty()){
            S += st.top();
            st.pop();
            if(!st.empty())
                S+='.';
        }
        return S;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends