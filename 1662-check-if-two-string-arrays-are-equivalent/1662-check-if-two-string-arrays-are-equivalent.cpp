class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
        
        int n = word1.size();
        int m = word2.size();
        
        string s1 = "" , s2 = "";
        
        for(int i = 0 ; i < n ; i++)
        {
            for(auto x : word1[i])
                s1 = s1 + x;
        }
        for(int i = 0 ; i < m ; i++)
        {
            for(auto x : word2[i])
                s2 = s2+x;
        }
        
        if(s1.size() == s2.size())
        {
            for(int i = 0 ; i < s1.size() ;i++)
            {
                if(s1[i] != s2[i])
                    return false;
            }
            return true;
        }
        return false;
        
    }
};