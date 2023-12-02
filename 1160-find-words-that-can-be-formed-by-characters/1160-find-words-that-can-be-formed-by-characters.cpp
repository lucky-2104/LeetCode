class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        
        unordered_map<char , int> mp;
        
        for(int i = 0 ; i < chars.size() ; i++)
        {
            if(mp.find(chars[i]) == mp.end())
                mp.insert({chars[i] , 1});
            else
                mp[chars[i]]++;
        }
        int count = 0;
        for(int i = 0 ; i < words.size() ; i++)
        {
            int count_temp = 0;
            unordered_map<char,int> temp(mp.begin() , mp.end());
            for(auto x : words[i])
            {
                if(temp.find(x) == mp.end() or temp[x] == 0){
                    count_temp = 0;
                    break;
                }
                
                else
                {
                    temp[x]--;
                    count_temp++;
                }
            }
            count = count + count_temp;
        }
        return count;
        
    }
};