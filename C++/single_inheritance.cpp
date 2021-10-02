// Single Inheritance basic code for understanding
#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "Inherited";
    }
};
class B : public A
{
};

int main()
{
    B b;
    b.func(); // class B inherited class A
}

// output = inherited