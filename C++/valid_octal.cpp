#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int x,d;
    cout<<"Enter a number";
    cin>>x;


   while(x>0){




        d=x%10;
        if(d>=8)
        {
            cout<<"not octal";
            return 0;

        }
         x/=10;
    }
cout<<"Octal";
    getch();
    return 0;

}
