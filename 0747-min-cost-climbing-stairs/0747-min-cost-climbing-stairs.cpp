class Solution {
public:

    int main_min(vector<int>& cost , int n ,vector<int>& dp)
    {

        if(n >= cost.size() )return 0;

        if(dp[n] != -1)
        return dp[n];

        return dp[n] = cost[n] + min(main_min(cost , n+1 , dp) , main_min(cost , n+2 , dp));

    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1 , -1);
       return min(main_min(cost , 0 , dp),main_min(cost , 1 , dp));
        
    }
};