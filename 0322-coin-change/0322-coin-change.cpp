class Solution {
public:
    int f(int ind , int amount , vector<int>& coins , vector<vector<int>>& dp)
    {
        //Base case
        if(ind == 0)
        {
            if(amount % coins[0] == 0)
            return (amount / coins[0]);
            else
            return 1e7;
        }

        if(dp[ind][amount] != -1)
        return dp[ind][amount];

        //main case
        int nottake = 0+f(ind - 1 , amount , coins , dp);
        int take = 1e7;
        if(amount >= coins[ind])
        take = 1+f(ind , amount - coins[ind] ,coins , dp);

        return dp[ind][amount] = min(nottake , take);
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size() , vector<int>(amount+1 , -1));

        int i = f(coins.size()-1 , amount , coins ,dp);
        if(i == 1e7)
        return -1;
        else 
        return i;
        
    }
};