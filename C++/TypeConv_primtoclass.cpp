#include<iostream>
using namespace std;

class Complex
{
    private:

    int a,b;

    public:

    void setdata(int x,int y)
    {
         a=x;   b=y;
    }

    void showdata()
    {
     cout<<"a="<<a<<" b="<<b;  
    }

    Complex (int x,int y)
    {
        a=x;  b=y;

    }

    Complex(){}

  
};


int main()
{
   Complex c1;                               //Here if We initialize during declaration, then there will be no need of default const. but here we are assingning value later,
   int x=5,y=7;                              // therefore we,ve got to make a default const.(that will run during decl. ) and a paramerterized one.
   c1=Complex(x,y);                                         // Can't convert primitive type to class type ------- The soln for this is to make a constructor which works as a convertor. 
   c1.showdata();

    return 0;
}