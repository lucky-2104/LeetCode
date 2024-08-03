class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        unordered_map<int,int> ump;
        for(auto x : arr)
        ump[x]++;

        for(auto x : target)
        ump[x]--;

        for(auto itr : ump)
        {
            int x = itr.first;
            int y = itr.second;
            if(y > 0 or y < 0) return false;
        }
        return true;
        
    }
};