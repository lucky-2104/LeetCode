class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long int max_count = 0;
        int patches = 0;
        int i = 0;
        while( max_count < n)
        {
            if(i < nums.size() and max_count+1 >= nums[i]){
                max_count = max_count + nums[i];
                i++;
            }
            else
            {
                int patch = max_count+1;
                max_count = max_count + patch;
                patches++;
            }
        }
        return patches;
        
    }
};