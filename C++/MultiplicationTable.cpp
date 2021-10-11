#include <iostream>
using namespace std;

int main ()
{
    int array [10];  //
    int a;

    cout << "Enter Number" << endl;
    cin >> a;

    cout << "---------------------" << endl;

    for (int i=0; i<=10; i++){
        cout << a <<" * "<< i << " = " << a*i << endl;
    }


    return 0;

}
