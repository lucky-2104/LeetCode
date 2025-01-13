class Solution {
public:
    int minimumLength(string s) {

        unordered_map<char,int> left;
        unordered_map<char,int> right;

        left[s[0]]++;

        for(char x : s){
            right[x]++;
        }
        right[s[0]]--;

        // int count = 0;
        for(int i = 1 ; i < s.size() ; i++){
            right[s[i]]--;

            if(left[s[i]] > 0 and right[s[i]] > 0)
            {
                right[s[i]]--;
                left[s[i]]--;
            }
            left[s[i]]++;
        }
        int count = 0;
        for(auto itr:left)
        count = count + itr.second;
        for(auto itr:right)
        count = count + itr.second;
        return count;


        


        
    }
};