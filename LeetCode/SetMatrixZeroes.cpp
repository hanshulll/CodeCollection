class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rowsize = matrix.size();
        int columnsize = matrix[0].size();
        //Initialising 2 vectors having rowsize & columnsize with 
        //all values equal to 1
        vector<int> rowmarker(rowsize,1); 
        vector<int> columnmarker(columnsize,1); 
        //These vectors are used to mark the positions where the element is zero
        //rowmarker will mark row positions and columnmarker will mak column positions
        for(int i =0;i<rowsize;i++)
        {
           for(int j =0;j<columnsize;j++)
           {
               if(matrix[i][j]==0)
               {
                   rowmarker[i]=0;// i used here to mark the row no.
                   columnmarker[j]=0;//j used here to mark the column no.
               }
           }
        }
         for(int i =0;i<rowsize;i++)
        {
           for(int j =0;j<columnsize;j++)
           {
               //The below if looks for any row or column(not particular position)
               //that has 0,if found that entire row/column is marked zero
               //courtesy of the or operator
               if(rowmarker[i]==0||columnmarker[j]==0)
                   matrix[i][j]=0;
           }
         }     
    }
};