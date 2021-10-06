#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int octalNum, decimalNum=0, i=0, rem;
    cout<<"Enter the Octal Number: ";
    cin>>octalNum;
    while(octalNum!=0)
    {
        rem = octalNum%10;
        decimalNum = decimalNum + (rem*pow(8,i));
        i++;
        octalNum = octalNum/10;
    }
    cout<<"\nEquivalent Decimal Value: "<<decimalNum;
    cout<<endl;
    return 0;
}