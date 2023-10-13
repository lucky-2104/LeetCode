class Solution {
public:

    int main_min(vector<int>& cost , int n , vector<int>& dp)
    {

        if(n <0) return 0;
        if(n == 0 or n == 1)
        return cost[n];

        if(dp[n] != -1)
        return dp[n];
        
        return dp[n] = cost[n]+min(main_min(cost,n-1,dp),main_min(cost,n-2,dp));

    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n,-1);

        return min(main_min(cost,n-1,dp),main_min(cost,n-2,dp));
        
    }
};