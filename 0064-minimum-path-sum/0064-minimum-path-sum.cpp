class Solution {
public:


    int sum_min(vector<vector<int>> &grid , int i , int j ,vector<vector<int>>& dp)
    {
        if(i == 0 and j == 0)
        return grid[i][j];

        if( i < 0 or j < 0 )
        return 1e9;

        if(dp[i][j] != -1)
        return dp[i][j];

        int up = grid[i][j] + sum_min(grid , i-1 , j,dp);
        int left = grid[i][j] +sum_min(grid , i, j-1,dp);

        return dp[i][j] = min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() , vector<int>(grid[0].size(),-1));
        return sum_min(grid , grid.size()-1 , grid[0].size()-1 , dp);
    }
};