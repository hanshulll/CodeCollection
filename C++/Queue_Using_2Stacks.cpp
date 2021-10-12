/*Implement Queue Using two Stacks */

#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
   
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    while(s1.empty()!=true){
     int temp=s1.top();
    s1.pop();
    s2.push(temp);}
    if(s2.empty()==true) return -1;
    
        int temp=s2.top(); s2.pop();
        while(s2.empty()!=true){
     int temp=s2.top();
    s2.pop();
    s1.push(temp);}
        return temp;
}
/*############################################################################################################################*/