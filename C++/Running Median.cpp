#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<int> leftheap;
    priority_queue<int,vector<int>,greater<int>> rightheap;
    int d;
    cin>>d;
    leftheap.push(d);
    float med=d;
    cout<<"Median is "<<med<<endl;
    cin>>d;
    while(d!=-1){
        if(leftheap.size()>rightheap.size()){
            if(d<med){
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }else{
                rightheap.push(d);
            }
            med=(rightheap.top()+leftheap.top())/2.0;
        }
        if(leftheap.size()==rightheap.size()){
            if(d<med){
                leftheap.push(d);
                med=leftheap.top();
            }else{
                rightheap.push(d);
                med=rightheap.top();
            }
        }else{
            if(d<med){
                leftheap.push(d);
            }else{
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            med=(rightheap.top()+leftheap.top())/2.0;
        }
        cout<<"Median is "<<med<<endl;
        cin>>d;
    }
    cout<<endl;
    return 0;

}