class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        int n = nums.size();
        int m = l.size();
        for(int i = 0 ; i < m ; i++)
        {
            vector<int> temp(nums.begin() + l[i] , nums.begin() + r[i]+1);
            
            //For 1 element
            if(temp.size() == 1 or temp.size() == 0)
            {
                ans.push_back(true);
                break;
            }
            
            //For more than 2 element
            sort(temp.begin() , temp.end());

            int flag = 0;
            int diff = temp[1] - temp[0];
            for(int i = 2 ; i < temp.size() ; i++)
            {
                if(temp[i] - temp[i-1] != diff)
                {
                    ans.push_back(false);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            ans.push_back(true);
        }
        return ans;
    }
};