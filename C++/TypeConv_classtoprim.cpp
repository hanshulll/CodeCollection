#include<iostream>
using namespace std;

class Complex
{
    private:

    int a,b;

    public:

    void setdata(int x)
    {
         a=x;
    }

    operator int ()                                        //To convert class type to primitive datatype, we use casting operator(operator).
    {                                                       // It is a member function. After operator keyword, we write that datatype to which we want to convert.(here int)
         return (a);
    }
};


int main()
{
    Complex c1;
    c1.setdata(8);
    int x;
    x=c1;
    cout<<x;
    return 0;
}