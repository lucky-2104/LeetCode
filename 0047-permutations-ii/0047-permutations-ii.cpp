class Solution {
public:

    void backtrack(vector<int>& nums , vector<int>& path  , vector<bool>& used , vector<vector<int>>& res){
        if(path.size() == nums.size()){
            res.push_back(path);
            return; 
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(used[i]) continue;

            if(i > 0 and nums[i] == nums[i-1] and !used[i-1]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums,path,used,res);
            path.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permu(vector<int> nums){
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size() , false);
        backtrack(nums,path , used , res); 
        return res;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> result;

        result = permu(nums);

        set<vector<int>> uniq;
        for(auto x : result){
            uniq.insert(x);
        }

        vector<vector<int>> result1;
        for(auto x : uniq){
            result1.push_back(x);
        }

        return result1;

        
    }
};