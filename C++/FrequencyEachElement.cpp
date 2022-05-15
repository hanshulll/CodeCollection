#include<iostream>
#include<vector>
using namespace std;

void frequency(vector<int>& arr) {
    int size = arr.size();

    vector<bool> visited(size, false);

    for(int i = 0; i < size; i++) {
        if(visited[i] == true) continue;

        int count = 1;
        for(int  j = i+1; j < size; j++) {
            if(arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << ": " << count << endl;
    }
}

int main() {
    vector<int> a1 = {1,1,1,3,4,5,6,6,5,4,6,7,4,3,3};
    cout << "CASE #1: ";
    for(int e: a1) cout << e << " ";
    cout << endl;
    frequency(a1);

    vector<int> a2 = {45,56,3,3,4,5,7,8,8,34,3,5,235,2,35,25,236,2,35,26,23,34};
    cout << "\nCASE #2: ";
    for(int e: a2) cout << e << " ";
    cout << endl;
    frequency(a2);

    vector<int> a3 = {435,5,23,2,35,23,5,25,6,7,3,7,456,345,435,2};
    cout << "\nCASE #3: ";
    for(int e: a3) cout << e << " ";
    cout << endl;
    frequency(a3);

    return 0;
}