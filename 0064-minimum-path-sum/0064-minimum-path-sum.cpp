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
        vector<vector<int>> dp(grid.size() , vector<int>(grid[0].size(),0));

        dp[0][0] = grid[0][0];

        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++ )
            {
                if(i == 0 and j ==0 )
                continue;
                else
                {
                    int down = i > 0 ? grid[i][j] + dp[i-1][j] : 1e9;
                    int right = j > 0 ?grid[i][j] + dp[i][j-1] : 1e9;
                    dp[i][j] = min(down,right);
                }
            }
        }

        return dp[grid.size()-1][grid[0].size()-1];
        // return sum_min(grid , grid.size()-1 , grid[0].size()-1 , dp);
    }
};