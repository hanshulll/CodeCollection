#include<iostream>
#include<stack>

using namespace std;

void reverseStack(stack<int> s1){
  stack<int> s2;

  int n = s1.size();

  for(int i=0;i<n;i++){
    s2.push(s1.top());
  }
  s1 = s2;  
}

int main(){


  stack<int> s;
  for(int i=1;i<=5;i++){
    s.push(i);
  }

  reverseStack(s);     


  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }

  return 0;
}