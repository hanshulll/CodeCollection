class Solution {
public:
   int islandPerimeter(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        int perimeter=0,row,col;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    row=i;
                    col=j;
                }
            }
        }
        dfs(grid,row,col,perimeter,vis);
        
        return perimeter;
        
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int &perimeter,vector<vector<bool>> &vis)
    {
        if(vis[i][j]==true||grid[i][j]==0) return;
        vis[i][j]=true;
        if(i-1<0||grid[i-1][j]==0) perimeter++;
       
        if(j-1<0||grid[i][j-1]==0)perimeter++;
        if(i+1>=grid.size()||grid[i+1][j]==0)perimeter++;
        if(j+1>=grid[0].size()||grid[i][j+1]==0)perimeter++;
        
        if(i+1<grid.size())dfs(grid,i+1,j,perimeter,vis);
        if(i-1>=0)dfs(grid,i-1,j,perimeter,vis);
        if(j+1<grid[0].size())dfs(grid,i,j+1,perimeter,vis);
        if(j-1>=0)dfs(grid,i,j-1,perimeter,vis);
    }
};
