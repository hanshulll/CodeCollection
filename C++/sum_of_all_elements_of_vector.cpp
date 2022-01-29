#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v{1, 2, 3, 4, 5};
	int sum = 0;
	for (auto elements : v) {
		sum += elements;
	}
	cout << sum;
  
	return 0;
}
