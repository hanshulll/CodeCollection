//Problem statement
//https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string isValid(string s) {
    string ans="NO";
    int b[26] = {};
    int n = s.length();
    
    for (int i=0; i<n;i++)
        b[s[i] - 'a']++;

    for (int i=-1; i < 26;i++) {
        if (i >= 0 and b[i] == 0)
            continue;
        if (i >= 0)
             b[i]--;
        set<int> x;
        for (int j = 0; j < 26; j++) {
            if (b[j])
            x.insert(b[j]);
        }
        if (x.size() == 1)
            ans = "YES";
        if (i >= 0)
            b[i]++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
