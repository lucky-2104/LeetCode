class Solution {
public:
    
    int reverse(int a)
    {
        int res = 0;
         while(a > 0)
         {
             res = res * 10 + a % 10 ;
             a = a/10;
         }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int modulo = 1e9+7;
        int res = 0;
        unordered_map<int , int> mp;
        
        for(int i = n-1 ; i >= 0 ; i-- )
        {
            int diff = nums[i] - reverse(nums[i]);
            if(mp.count(diff) == true)
            {
                res = (res + mp[diff]) % modulo ;
            }
            mp[diff]++;
        }
        return res;
        
        
    }
};