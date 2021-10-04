#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[n];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[i])
            {
                int temp = ar[j];
                ar[j] = ar[i];
                ar[i] = temp;
                cout<<ar[i];
            }
        }
    }
    for (int p = 0; p < n; p++)
    {
        cout << ar[p] <<" ";
    }cout<<endl;
    return 0;
}