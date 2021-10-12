#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;

void push(int val)
{
    s.push(val);
    if(ss.size()==0 || val<=ss.top())
    {
        ss.push(val);
    }

}
int pop()
{
    int result;
    if(s.size()==0)
    {
        return -1;
    }
    else
    {
        if(s.top()==ss.top())
        {
          result=ss.top();
          s.pop();
          ss.pop();
        }
        else
        {
            result=s.top();
            s.pop();
        }

    }
    return result;

}

int getmin()
{
    int result;
    if(ss.size()==0)
    {
        return -1;
    }
    else
    {
         result=ss.top();

    }
    return result;
}


int main()
{
   int print;
   push(11);
   push(9);
   push(7);
   pop();
   push(10);
   cout<<getmin();

}
