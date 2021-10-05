 bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here
        int i=0;
        int j=m-1;
        
        while(i<n && j<m)
        {
            if(matrix[i][j]==x)
                return true;
            if(matrix[i][j]>x)
                j--;
            else
                i++;
        }
        
        return false;
    }
