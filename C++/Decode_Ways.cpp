//Decode Ways : https://leetcode.com/problems/decode-ways/
#include <bits/stdc++.h>
using namespace std;


 int countDigit(string s, int n)
{
    
    int count[n+1];
    count[0] = 1;
    count[1] = 1;
    
    if(s[0]=='0') 
         return 0;
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
 
        
        if (s[i-1] > '0')
            count[i] = count[i-1];
 
       
        if (s[i-2] == '1' ||
              (s[i-2] == '2' && s[i-1] < '7') )
            count[i] += count[i-2];
    }
    return count[n];
}

int main()
{
    string s;
    cin>>s;

    int n= s.length();

    cout<<countDigit(s,n);


}
