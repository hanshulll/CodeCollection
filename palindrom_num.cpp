#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int rev(int x){
        long reverse=0;
        while(x>0){
            reverse=reverse*10 +x%10;
            x=x/10;
        }
        return reverse;
    }
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(rev(x)==x)
            return true;
        return false;
        
    }
    
int main()
{
    int x;
    cin>>x;
    cout<<isPalindrome(x);
    return 0;

    return 0;
}
