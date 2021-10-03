#include <iostream>
using namespace std;

int calculate(int, int);

int main()
{
    int base, power, result;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power number(positive integer): ";
    cin >> power;

    result = calculate(base, power);
    cout << base << "^" << power << " = " << result;

    return 0;
}

int calculate(int base, int power)
{
    if (power != 0)
        return (base*calculate(base, power-1));
    else
        return 1;
}
