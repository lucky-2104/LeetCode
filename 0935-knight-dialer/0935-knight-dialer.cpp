class Solution {
private:
    int mod = 1e9+7;
public:
    int f(int i ,int n , int count , vector<vector<int>>& dialpad , vector<vector<int>>& dp)
    {
        if(count == n)
        {
            return 1;
        }
        
        if(dp[i][count] != -1)
            return dp[i][count] % mod;
        
        int ans = 0;
        for(auto x : dialpad[i])
        {
            int temp = f(x , n , count+1 , dialpad , dp ) %mod;
            ans = ((ans)%mod + temp)%mod;
        }
        return dp[i][count] = ans % mod;
        
    }
    int knightDialer(int n) {
        
        vector<vector<int>> dialpad = {{4,6} , {6,8} , {7,9} , {4,8} , {0,3,9} , {} , 
                                       {1,7,0} , {2,6} , {1,3} , {4,2}};
        
        vector<vector<int>> dp(10 , vector<int>(n+1 , -1));
        int ans = 0;
        
            
        for(int i = 0 ; i < 10 ; i++)
        {
            int temp = f(i , n , 1 , dialpad , dp);
            
            ans = ((ans)%mod + temp) % mod;
        }
        return ans;
        
        
    }
};