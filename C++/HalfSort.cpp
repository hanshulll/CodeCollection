#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nsize;
    cin>>nsize;
    int arr[nsize];

    for(int i=0;i<nsize;i++)
    {
        int temp;
        cin>>temp;
        arr[i]=temp;
    }

    sort(arr,arr+(nsize/2));
    sort(arr+(nsize/2),arr+nsize,greater<int>());

    for(int i=0;i<nsize;i++)
    {
        cout<<arr[i];
    }
}
