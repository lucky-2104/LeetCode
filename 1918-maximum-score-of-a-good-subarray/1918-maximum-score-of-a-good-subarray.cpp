class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int max_ans = nums[k];
        int l = k;
        int r = k;
        int curr_min = nums[k];

        while(l >  -1 and r < nums.size())
        {
            int left = l > 0 ? nums[l-1] : 0;
            int right = r < nums.size()-1? nums[r+1] : 0;
            if(left > right)
            {
                l--;
                curr_min = min(curr_min,left);

            }
            else
            {
                r++;
                curr_min = min(curr_min,right);
            }

            max_ans = max(max_ans , curr_min*(r-l+1));

        }
        return max_ans;
    }
};