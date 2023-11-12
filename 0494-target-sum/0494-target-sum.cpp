class Solution {
public:
    int f(int indx, int sum, int target, vector<int>& nums)
    {
        //base case;
        if(indx == 0)
        {
            if(sum == target and sum - 2*nums[0] == target)
            return 2;
            else if(sum == target or sum - 2*nums[0] == target)
            return 1;
            else 
            return 0;
        }

        int pos = 0 + f(indx -1 , sum , target , nums);
        int neg = 0 + f(indx - 1 , sum - 2*nums[indx] , target ,nums);

        return  pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        sum = sum + nums[i];
        
        // vector<vector<int>> dp(nums.size() , vector<int>(sum+1 , -1));
        return f(nums.size()-1 , sum , target , nums);
        
    }
};