#include <iostream>
using namespace std;

bool pairSum(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }

    return false;
}

int main()
{

    int arr[] = {2, 3, 4, 7, 9, 10, 13, 20};
    int k = 14;
    cout << pairSum(arr, 8, k) << endl;
    return 0;
}
