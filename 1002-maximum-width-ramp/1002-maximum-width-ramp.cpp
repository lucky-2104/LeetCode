class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        int result = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(s.empty() || nums[s.top()] > nums[i]){

                s.push(i);
                cout << nums[s.top()];

            }
        }

        for(int j = n-1 ; j >= 0 ; j--)
        {
            while(!s.empty() && nums[j] >= nums[s.top()]){
                result = max(result , j - s.top());
                s.pop();
            }
        }

        return result;
    }
};