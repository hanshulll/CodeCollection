Given an array of number of laddus from boss which are arranged and distributed unequally by his pa,
you need to help the boss to distribute again such that all of them get equal Laddus 
if its not possible to distribute equally then no one will get Laddus
if possible then print how many people got extra Laddus and which employee got the extra laddus and redistributed array.
  
Example: 

 I/P : a[] = {1,4,2,5}  
 O/P : 2
      a[] = {1,3}
      a[] = {3,3,3,3} 

  
#include <bits/stdc++.h>

using namespace std;

// Function to distribute equal laddus from unequal

// distributed laddus and print the the employees who got

// extra laddos

void solve(int a[], int n)

{

    // Vector to store who got extra laddus

    std::vector<int> sa;

    int sum = 0;

    // Calculating the sum of array

    for (int i = 0; i < n; i++) {

        sum = sum + a[i];
    }

    // sum divided by the size n

    int sbn = sum / n;

    int c2 = 0;

    int count = 0;

    // case -1

    if (sum % n != 0) {

        cout << "-1" << endl;

        return;
    }

    // Case - 2

    for (int i = 0; i < n; i++) {

        if (a[i] > sbn) {

            c2++;

            sa.push_back(i + 1);
        }
    }

    // Number of employees who got extra laddus

    cout << c2 << endl;

    // Which employee got extra laddus

    cout << "Employee who got extra : ";

    for (int i = 0; i < sa.size(); i++) {

        cout << sa[i] << " ";
    }

    cout << "\n";

    // Re-Distributed equal ladus

    cout << "Re-Distributed equal ladus :  ";

    for (int i = 0; i < n; i++) {

        while (a[i] < sbn) {

            a[i] = a[i] + 1;
        }

        while (a[i] > sbn) {

            a[i] = a[i] - 1;
        }

        cout << a[i] << " ";
    }

    cout << endl;
}
}
