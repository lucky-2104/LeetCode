class Solution {
public:
    int maxDifference(string s) {

        unordered_map<char,int> ump;

        for(auto itr : s){
            ump[itr]++;
        }

        int max_value = INT_MIN;
        int min_value = INT_MAX;

        for(auto itr : ump){

            if(itr.second % 2 == 1) max_value = max(itr.second , max_value);
            if(itr.second % 2 == 0)min_value = min(itr.second , min_value);
        }

        return max_value - min_value;
        
    }
};