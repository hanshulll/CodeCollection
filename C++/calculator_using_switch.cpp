#include<iostream>
using namespace std;

main()
{
    cout<<"Enter two numbers for arithmetic operations"<<endl;
    double a,b,c;
    cin>>a;
    cin>>b;
    cout<<"Enter operator"<<endl;
    char d;
    cin>>d;
    switch (d)
    {
    case '+':
        c=a+b;
        break;
    case '-':
        c=a-b;
        break;
    case '*':
        c=a*b;
        break;
    case '/':
        c=a/b;
        break;
    default:
        cout<<"Invalid Input";
    }
        cout<<"The ouput is "<<c;
}
