#include <bits/stdc++.h>
using namespace std;

void findSubarrayInversions(int arr[], int n)
{

	int inversions[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			inversions[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int ans = 0;
			for (int x = i; x <= j; x++) {
				for (int y = x; y <= j; y++) {
					if (arr[x] > arr[y])
						ans++;
				}
			}

			inversions[i][j] = ans;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << inversions[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{

	int n = 7;
	int arr[n] = { 3, 6, 1, 6, 5, 3, 9 };

	findSubarrayInversions(arr, n);
}
