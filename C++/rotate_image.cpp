class Solution {
public:
    void transpose(int x, vector<vector<int>>& matrix){
        // code for transpose of the matrix using recursion
        if(x== matrix.size()){
            return;
        }
        for(int i=x;i<matrix.size();i++){   
            swap(matrix[i][x],matrix[x][i]);
        }
        transpose(x+1, matrix);
    }
    void rotate(vector<vector<int>>& matrix) {
        // transpose and reverse 
        transpose(0,matrix);
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
