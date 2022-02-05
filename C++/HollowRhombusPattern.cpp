#include <iostream>
using namespace std;

int main()
{
            int n;  // No. of rows or columns or rhombus of size n
            cout<<"Enter the size of the rhombus";
            cin>>n;
            for (int i=1; i<=n; i++)
            {   
                for (int j=1; j<=n-i; j++)
                {
                    cout<<" ";
                }
                for (int j=1; j<=n; j++)
                {
                    if (i == 1 || i == n)
                    {
                        cout<<"*";
                    }
                    else if (j == 1 || j == n)
                    {
                        cout<<"*";
                    }
                    else
                    { 
                        cout<<" ";
                    }
                }
                cout<<endl;
            }
}
