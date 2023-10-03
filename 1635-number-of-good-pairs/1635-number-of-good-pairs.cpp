class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int count = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            int j = 0 ;
            while(j < nums.size())
            {
                if( j == i)
                {
                    j++;
                    continue;
                }
                if(nums[j] == nums[i] and i < j)
                count++;

                j++;
            }
        }
        return count;
    }
};