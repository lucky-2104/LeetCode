class Solution {
public:
    int maxScore(string s) {
        
        unordered_map<char , int> ump;
        ump['1'] = 0;
        
        for(auto x : s)
        {
            if (x == '1')
                ump[x]++;
        }
        
        int count0 = 0; 
        int ans = INT_MIN;
        
        for(int i = 0 ; i < s.size()-1 ; i++)
        {
            if(s[i] == '0')
                count0++;
            if(s[i] == '1')
                ump['1']--;
            
            if(count0 + ump['1'] > ans)
            ans = count0 + ump['1'];
        }
        
        return ans;
        
    }
};