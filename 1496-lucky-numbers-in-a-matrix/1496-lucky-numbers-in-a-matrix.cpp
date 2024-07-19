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
        for(int i = 0 ; i < m ;i++){

            for(int j = 0 ; j < n ; j++)
            {
                if(matrix[i][j] == min_row[i] and matrix[i][j] == max_col[j])
                ans.push_back(matrix[i][j]);
            }
        }
        return ans;
        
    }
};