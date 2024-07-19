class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(); // no. of rows 
        int n = matrix[0].size(); // no. of cols
        vector<int> min_row(m , 0); 
        vector<int> max_col(n , 0); 

        for(int i = 0 ; i < m ; i++)
        {
            min_row[i] = *min_element(matrix[i].begin() , matrix[i].end());
        }
        for(int i = 0 ; i < n ; i++)
        {
            int temp = INT_MIN;
            for(int j = 0 ; j < m ;j++)
            {
                temp = max(temp , matrix[j][i]);
            }
            max_col[i] = temp;
        }

        vector<int> ans;
        int row = 0;
        for(int i = 0 ; i < m ;i++)
        {
            int col = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(matrix[i][j] == min_row[row] and matrix[i][j] == max_col[col])
                ans.push_back(matrix[i][j]);
                col++;
            }
            col = 0;
            row++;
        }
        return ans;
        
    }
};