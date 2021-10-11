#include <iostream>
using namespace std;

char letraDNI(unsigned int dni);

char letraDNI(unsigned int dni)
{
    return "TRWAGMYFPDXBNJZSQVHLCKE"[dni % 23];
}

int main()
{
    int dni;
    cout << "Introduce el DNI: ";
    cin >> dni;
    char letra = letraDNI(dni);
    cout << dni << "-" << letra;
    return 0;
}
