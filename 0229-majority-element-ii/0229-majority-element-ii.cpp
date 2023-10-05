class Solution {
public:

    map<int ,int> count;
    vector<int> majorityElement(vector<int>& nums){

        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(count.find(nums[i]) == count.end())
            count.insert({nums[i] ,1});
            else
            count[nums[i]]++;
        }

        for(auto it = count.begin() ; it != count.end();it++)
        {
            if(it->second > nums.size()/3)
            ans.push_back(it->first);
        }
        return ans;
        
    }
};