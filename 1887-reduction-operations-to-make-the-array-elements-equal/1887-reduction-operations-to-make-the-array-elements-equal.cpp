class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<int> indices;
        int next_int = nums[0];
        
        for(int i = 0 ; i < nums.size() ;i++)
        {
            if(next_int  != nums[i])
            {
                next_int = nums[i];
                indices.push_back(i-1);
            }
        }
        indices.push_back(nums.size()-1);
        int size = nums.size() - 1;
        int sum1 = 0;
        for(int i = indices.size() - 1 ; i >= 0 ; i--)
        sum1 = sum1 + abs(indices[i]-size);
        return sum1;
            
            
        
    }
};