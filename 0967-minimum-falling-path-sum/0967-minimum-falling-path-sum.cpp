class Solution {
public:

    // int f(int i , int j , vector<vector<int>>& matrix , vector<vector<int>>& dp)
    // {
    //     if(j < 0 or j >= matrix.size())
    //     return 1e7;
    //     if(i == matrix.size() - 1)
    //     return matrix[i][j];

    //     if(dp[i][j] != -1)
    //     return dp[i][j];

    //     int down = matrix[i][j]+f(i+1,j,matrix,dp); 
    //     int dl = matrix[i][j]+f(i+1,j-1,matrix,dp);
    //     int dr = matrix[i][j]+f(i+1,j+1,matrix,dp);

    //     return dp[i][j] = min(down,min(dl,dr));

    // }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> dp(m , vector<int>(m, 0));
        for(int i = 0 ; i < m ;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1 ; i < m ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int down =dp[i-1][j] + matrix[i][j];
                int dl = j-1 >= 0 ? dp[i-1][j-1] + matrix[i][j] : 1e7;
                int dr = j+1 < m ? dp[i-1][j+1] + matrix[i][j] : 1e7;

                dp[i][j] = min(down ,min(dl,dr));
            }
        }
        int mini = dp[m-1][0];
        for(int i = 1 ; i < m;i++)
        {
            mini = min(mini , dp[m-1][i]);
        }
        return mini;


        // for (int i = 0 ; i < matrix.size() ; i++)
        // {
        //     mini = min(mini , f(0,i,matrix,dp));
        // }
        // return mini;

    }
};