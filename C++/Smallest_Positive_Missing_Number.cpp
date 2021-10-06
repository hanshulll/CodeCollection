// Problem asked in samsung,snapdeal etc.
// We are given an array of size N and we have to find the smallest missing(positive) number in that array

// Base Idea:-
// --> Build a boolean check[] array that will depict if any element x is present in the array or not
// --> Iterate over the array and mark non-negative a[i] as true

#include<iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    const int N = 1e6 + 2;
    bool check[N];
    for(int i=0;i<N;i++)
    {
        check[i] = false; // False can be used but 0 to increase speed
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i] >= 0)
        {
            check[arr[i]] = true;
        }
    }
    int ans = -1;
    for(int i=1;i<N;i++)
    {
        if(check[i]==false)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}