//problem link:- https://www.codechef.com/problems/FLOW004

#include<iostream>
using namespace std;

int getFirstAndLastSum(int num){
    int first,last=num%10;
    while(num){
        if(num%10==num){
            first=num;
        }
        num = num/10;
    }
    
    return first+last;
}

int main(){
    int testCases,num;
    cin>>testCases;
    for(int i=0;i<testCases;++i){
        cin>>num;
        cout<<getFirstAndLastSum(num)<<endl;  
    }
    return 0;
}
