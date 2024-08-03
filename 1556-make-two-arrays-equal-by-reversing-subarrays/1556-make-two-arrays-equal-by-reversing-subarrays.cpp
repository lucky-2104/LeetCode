class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        unordered_map<int,int> ump;
        for(auto x : arr)
        ump[x]++;

        for(auto x : target)
        ump[x]--;

        for(auto itr : ump)
            if(itr.second > 0 or itr.second < 0) return false;
        return true;
        
    }
};