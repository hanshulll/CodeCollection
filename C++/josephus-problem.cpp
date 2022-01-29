// problem statement: https://en.wikipedia.org/wiki/Josephus_problem
// Complexity O(n)
// Language: CPP
#include <bits/stdc++.h>

using namespace std;

void josephus(vector<int> a, int k, int idx) {
  if (a.size() == 1) {
    cout << a[0] << endl;  // single person case
    return;
  }
  idx = ((idx + k) % a.size());  // index of person who will die
  a.erase(a.begin() + idx);      // remove him/her
  josephus(a, k, idx);           // recursively call for rest n-1 people
}

int main() {
  int n, k, idx;
  printf("Enter The Number of People Standing\n");
  scanf("%d", &n);
  printf("Enter The Number of People To Be Skipped\n");
  scanf("%d", &k);
  k--;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    a.push_back(i);
  }
  josephus(a, k, idx);
}
