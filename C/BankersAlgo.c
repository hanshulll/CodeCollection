#define n 4     // Number of processes
#define m 2     // Number of resources

#include <stdio.h>
int main ()
{
  int i, j, k;
  int alloc[n][m] = {     // This is the multi-dimensional array containing the allocation matrix
    {1, 2},
    {0, 1},
    {1, 0},
    {2, 0},
  };
  
  int max[n][m] = {     // This is the multi-dimensional array containing the maximum-need matrix
    {4, 2},
    {1, 2},
    {1, 3},
    {3, 2},
  };

  int avail[m] = {1, 1};  // This array contains the information about the available resources

  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++)
  {
    f[k] = 0;
  }
  int need[n][m];
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }
  int y = 0;
  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      if (f[i] == 0)
      {
        int flag = 0;
        for (j = 0; j < m; j++)
        {
          if (need[i][j] > avail[j])
          {
            flag = 1;
            break;
          }
        }

        if (flag == 0)
        {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            avail[y] += alloc[i][y];
          f[i] = 1;
        }
      }
    }
  }

  printf ("SAFE Sequence is: \n");      // Note: The processes are named from P1, P2,...
  for (i = 0; i < n - 1; i++)
    printf (" P%d ->", ans[i]+1);
  printf (" P%d", ans[n - 1]+1);
  return (0);
}
