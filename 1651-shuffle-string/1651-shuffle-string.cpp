class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        map<int,char> mp;

        for(int i = 0 ; i < indices.size(); i++){
            mp[indices[i]] = s[i];
        }

        string ans = "";

        for(auto itr : mp)
            ans = ans + itr.second;
        
        return ans;  
    }
};