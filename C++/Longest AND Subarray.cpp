#include <iostream>
#include <cmath>
using namespace std;
// function to find the highest 2's power number less than the given number
int power(int x)
{

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x ^ (x >> 1);
}
// function to check if a number is a power of two
bool PowerTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;                                                             // what will be doing is if the given number can be written in 2's power for example  8 ,16 etc 
                                                                           //then answer always in this case is n-n/2                                                                           //
        cin >> n;                                                          

        int previouspower2 = power(n);
        int s = previouspower2 / 2;

        if (PowerTwo(n))                                                              
        {
           // int m = n - 1;
            cout <<n-n/2<<endl;
            continue;
        }
        if ((n - previouspower2 + 1) > (previouspower2 - s))                 
        {                                                                 
            cout << n - previouspower2 + 1 << endl;
            continue;
        }
        else
            cout << previouspower2 - s << endl;
    }
    return 0;
}
