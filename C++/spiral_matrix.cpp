/* 
Problem Statement
Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.
*/

/*
Time Complexity : O(NxM)

*/


#include <iostream>
#include <cstdio>

using namespace std;
int findK(vector<vector<int>> &a, int n, int m, int k)
{
    int xStart = 0,yStart = 0,xEnd = n,yEnd = m;
    int cnt = 1;
    while(xStart<xEnd && yStart < yEnd){
        int i=xStart,j=yStart;
        while(j<yEnd-1){
            
            if(cnt == k){
                return a[i][j];
            }
            cnt += 1;
            j += 1;
        }
        while(i<xEnd-1){
            if(cnt == k){
                return a[i][j];
            }
            cnt += 1;
            i += 1;
        }
        while(j>yStart){
            if(cnt == k){
                return a[i][j];
            }
            cnt += 1;
            j -= 1;
        }
        while(i>xStart){
            if(cnt == k){
                return a[i][j];
            }
            cnt += 1;
            i -= 1;
        }
        xStart += 1;yStart += 1;
        xEnd -= 1;yEnd -= 1;
    }
    return a[n/2][m/2];
    
}



int main()
{
    
    int n,m;
    int k=0;
    cin>>n>>m>>k;
    vector<vector<int>> a(n, vector<int>(m, 0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<findK(a,n,m,k);
    return(0);
}
