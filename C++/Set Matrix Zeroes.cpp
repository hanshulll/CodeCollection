/*
 if an element is 0, set its entire row and column to 0's, and return the matrix.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/


#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) 
{
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> row;
        set<int> col;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(row.count(i) or col.count(j))
                matrix[i][j] = 0;
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        
    }
int main()
{
  vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  setZeroes(v);
  return 0;
}
