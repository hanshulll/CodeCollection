/*Problem Description - You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
First print "YES", if there is a path, and "NO" otherwise.

If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). 
You can print any valid solution.*/


// Problem Link - https://cses.fi/problemset/task/1193/

#include <bits/stdc++.h>
using namespace std;
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'L', 'R'};
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>> rooms(n, vector<char> (m, '#'));
    int row = -1, col=-1;
    int row_f=-1, col_f =-1;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char c;
            cin>>c;
            
            rooms[i][j] = c;
            if(rooms[i][j]=='A')
            {
                row=i, col=j;
            }
        }
    }
    
    vector<vector<bool>> vis(n, vector<bool> (m,false));
   
    string ans;
    queue<pair<int, int>> q;
    int ct = 1;
    
    q.push({row, col});
    vis[row][col] = true;
    bool flag = false;
    
    vector<vector<int>> count(n, vector<int> (m,INT_MAX));
    count[row][col] = 0;
    
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            // cout<<x<<" "<<y<<endl;
            if(rooms[x][y]=='B')
            {
                flag=true;
                row_f=x, col_f=y;
                break;
            }
            for(int i=0; i<4; i++)
            {
                int X = x+dirX[i];
                int Y = y+dirY[i];
                
                if(X>=0 && Y>=0 && X<n && Y<m && !vis[X][Y] && rooms[X][Y]!='#')
                {
                    vis[X][Y] = true;
                    count[X][Y] = ct;
                    q.push({X,Y});
                }
            }
        }
        if(flag)
        {
            break;
        }
        ct+=1;
    }
    
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         cout<<count[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(!flag)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        
        for(int i=0; i<4; i++)
        {
            int x = row_f + dirX[i];
            int y = col_f + dirY[i];
            if(x<0 || y<0 || x>=n || y>=m)
            {
                    continue;
            }
            ct = min(ct, count[x][y]);
        }
        
        cout<<ct+1<<endl;
        
        while(ct>=0)
        {
            
            for(int i=0; i<4; i++)
            {
                int x = row_f + dirX[i];
                int y = col_f + dirY[i];
                if(x<0 || y<0 || x>=n || y>=m)
                {
                    continue;
                }
                if(count[x][y]==ct)
                {
                    ans+=dir[i];
                    row_f=x;
                    col_f=y;
                    ct--;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    
}