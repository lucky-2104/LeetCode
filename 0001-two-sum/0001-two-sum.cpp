class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        unordered_map<int,int> umap;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int comp = target - nums[i];
            if(umap.find(comp) != umap.end())
            {
                temp.push_back(i);
                temp.push_back(umap[comp]);
                return temp;
            }
            umap[nums[i]] = i;
        }
        return temp;
    }
        
};