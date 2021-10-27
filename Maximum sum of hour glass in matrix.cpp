#include<bits/stdc++.h>
using namespace std;
const int R = 5;
const int C = 5;
  
// Returns maximum sum of hour glass in ar[][]
int findMaxSum(int mat[R][C])
{
    if (R<3 || C<3)
        return -1;
  
    // Here loop runs (R-2)*(C-2) times considering
    // different top left cells of hour glasses.
    int max_sum = INT_MIN;
    for (int i=0; i<R-2; i++)
    {
        for (int j=0; j<C-2; j++)
        {
            // Considering mat[i][j] as top left cell of
            // hour glass.
            int sum = (mat[i][j]+mat[i][j+1]+mat[i][j+2])+
                      (mat[i+1][j+1])+
                  (mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2]);
  
            // If previous sum is less then current sum then
            // update new sum in max_sum
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}
  
// Driver code
int main()
{
    int mat[][C] = {{1, 2, 3, 0, 0},
                    {0, 0, 0, 0, 0},
                    {2, 1, 4, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 1, 0}};
    int res = findMaxSum(mat);
    if (res == -1)
        cout << "Not possible" << endl;
    else
        cout << "Maximum sum of hour glass = "
             << res << endl;
    return 0;
}
