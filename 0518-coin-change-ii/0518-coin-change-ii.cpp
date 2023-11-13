class Solution {
public:

    int f(int indx , int amount , vector<int>& coins , vector<vector<int>>& dp)
    {
        //base case
        if(indx == 0)
        return(amount % coins[0] == 0);

        //Memoization
        if(dp[indx][amount] != -1)
        return dp[indx][amount];

        //Main case
        int notpick = f(indx -1 , amount , coins,dp);
        int pick = 0;
        if(amount >= coins[indx])
        pick = f(indx , amount - coins[indx] , coins,dp);

        return dp[indx][amount]= pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() ,vector<int>(amount +1 ,-1));
        return f(coins.size()-1 , amount , coins,dp);
        
    }
};