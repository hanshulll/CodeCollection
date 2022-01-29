// Solution to diagonal movement code

#include <iostream>
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int sum = x+y;
    if((x+y)%2 == 0)
    {
        cout << "YES" << "\n";
    }
    else
    cout << "NO" << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
