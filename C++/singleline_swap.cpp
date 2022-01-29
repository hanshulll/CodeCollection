#include<iostream>
using namespace std;
//This code is to swap two numbers without 3rd variable in a single line
void swap(int *x,int *y)
{
  *x = *x + *y - (*y = *x);
}
int main()
{
  int a,b;
  cout<<"\nEnter the two numbers : ";
  cin>>a>>b;
  swap(&a,&b);
  cout<<"\n Value after Swap - a = "<<a<<" , b = "<<b<<endl;
  return 0;
}
