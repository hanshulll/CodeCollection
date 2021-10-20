#include<bits/stdc++.h>
using namespace std;
void duplicate(string str){
    map<char,int> mp;
    for(int i=0;i<str.length();i++){
        mp[str[i]]++;
    }
    for(auto x: mp){
        if(x.second>1){
            cout << x.first << " is repeated " << x.second << " times" << endl;
        }
    }

}
int main(){
    string str="test string";
    duplicate(str);

    return 0;
}