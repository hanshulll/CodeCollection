#include <bits/stdc++.h>
using namespace std; 
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

string longpalindrome(string s) {
    int n = s.length();
    int maxlen = 1, start = 0; // All substrings of length are palindromes.
    
    // Nested loop to mark start and end index.
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int flag = 1;
            // Check palindrome
            for (int k = 0; k < (j - i + 1)/2; k++) {
                if (s[i + k] != s[j - k])
                    flag = 0;
             // Palindrome
            if (flag && (j - i + 1) > maxlength) {
                start = i;
                maxlength = j - i + 1;
            }
            }
        }
    }
    printSubStr(s, start, start + maxlength - 1);

    
};

int main() {
    string s;
    cin>>s;
    cout << longpalindrome(s) << endl;
    return 0;   
    }
