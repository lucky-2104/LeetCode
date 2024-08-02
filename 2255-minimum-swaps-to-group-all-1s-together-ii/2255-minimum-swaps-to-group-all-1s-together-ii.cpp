class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0;

        int n= nums.size();
        for(int i = 0 ; i < nums.size() ; i++)
        if(nums[i] == 1) k++;

        int ans = 0;
        int i = 0 , j = 0;
        int count = 0;
        while(j < 2*nums.size())
        {

            if(j-i+1 <= k)
            {
                if(nums[j%n] == 1)count++;
                
            }
            else
            {
                if(nums[i%n] == 1) count--;
                if(nums[j%n] == 1) count++;
                i++;
                ans = max(count , ans);
            }
            j++;
        }
        return k-ans;
        
    }
};