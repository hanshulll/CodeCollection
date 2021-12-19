// Word Search - https://leetcode.com/problems/word-search/
#include <bits/stdc++.h>
using namespace std;

int n,m;
bool isvalid(int i, int j)
{
    return (0<=i && i<n && 0<=j && j<m);
}

bool rec(vector<vector<char>>& board,string word,int idx,int i, int j,vector<vector<bool>> &vis)
{
    if(idx==word.length())
        return true;
    if(!(isvalid(i,j) && !vis[i][j] && word[idx]==board[i][j]))
        return false;
    vis[i][j] = true;
    bool f = false;
    f |= rec(board,word,idx+1,i-1,j,vis);
    if(f)
        return true;
    f |= rec(board,word,idx+1,i,j-1,vis);
    if(f)
        return true;
    f |= rec(board,word,idx+1,i+1,j,vis);
    if(f)
        return true;
    f |= rec(board,word,idx+1,i,j+1,vis);
    if(f)
        return true;
    vis[i][j] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) 
{
    n = board.size();
    m = board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            if(rec(board,word,0,i,j,vis))
                return true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>m; 
    vector<vector<char>> board;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    string word;
    cin>>word;
    if(exist(board,word))
        cout<<"Given word exists in the board\n";
    else
        cout<<"Given word does not exist in the board\n";

    return 0;
}





