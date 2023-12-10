class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> transpose_matrix(matrix[0].size() , vector<int>(matrix.size(),0));
        int row_new = 0 , col_new = 0;
        for(int row = 0 ; row < matrix.size() ; row++)
        {
            for(int col = 0 ; col < matrix[0].size() ; col++)
            {
                transpose_matrix[col][row] = matrix[row][col];
            }
        }
        return transpose_matrix;
        
    
        
        
    }
};