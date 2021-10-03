// Program for insertion sort using c++
#include <bits/stdc++.h>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}



//main
int main()
{
    int n;
    cout<<"Enter Number of Elements";
    cin>>n;

    int arr[n] ;
    cout<<"Enter Array Elements";
    for (int i = 0; i < n; i++)
		cin>> arr[i];
	
	insertionSort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
	return 0;
}



