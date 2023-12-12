class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int first_max = INT_MIN , sec_max = INT_MIN ;
        
        for(int i= 0 ; i < nums.size() ; i++)
        {
            if(nums[i] >= first_max)
            {
                sec_max = first_max;
                first_max= nums[i];
                
            }
            else if(nums[i] >= sec_max)
                sec_max= nums[i];
        }

        // cout << first_max << sec_max << endl;

        return ((first_max - 1) * (sec_max-1));


        
    }
};