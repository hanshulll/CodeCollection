// Hakerrank Question link- https://www.hackerrank.com/challenges/magic-square-forming/problem

#include <bits/stdc++.h>

using namespace std;

bool isMagic(vector<int>& m){
    const int magic = 15; //arbitrary
    int rsum{};
    for(int r{}; r < m.size(); ++r){
        rsum += m[r];
        if(r % 3 != 2) continue;
        if(rsum != magic) return false;
        rsum = 0;
    }
    // check each col
    int csum[3] = {0,0,0};
    for(int c{}; c < m.size(); ++c){
        csum[c % 3] += m[c];
    }
    if(csum[0] != magic || csum[1] != magic || csum[2] != magic)
        return false;
    
    int lrsum = m[0] + m[4] + m[8];
    int rlsum = m[2] + m[4] + m[6];
    
    if(lrsum != magic || rlsum != magic) return false;
    
    return true; // this matrix 'm' is magic!
}

int transformCost(vector<int>& m, vector<int>& n){
    //cost to transform from matrix 'm' to 'n'
    //as per the rule |a-b| = cost
    int total_cost{};
    for(int i{}; i < m.size(); ++i){
        total_cost += abs(
            m[i] - n[i]
        );
    }
    return total_cost;
}

int formingMagicSquare(vector<vector<int>> s) {
    int minimum_cost = INT_MAX;
    vector<int> flatten;
    for(auto& r : s){
        for(auto& c : r)
            flatten.push_back(c);  
    }
    vector<int> p = {1,2,3,4,5,6,7,8,9};
    //n! -> 9! 300k
    while(next_permutation(p.begin(), p.end())){
        if(!isMagic(p)) continue;
        //otherwise it is magic
        minimum_cost = min(
            minimum_cost, transformCost(flatten, p)
        );
    }
    
    return minimum_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
