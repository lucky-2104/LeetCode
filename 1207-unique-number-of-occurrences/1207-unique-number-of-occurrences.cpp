class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int , int> ump;
        for(int i = 0 ; i<arr.size() ;i++)
        ump[arr[i]]++;
        
        int max_count = INT_MIN;
        
        for(auto x : ump)
        max_count = max(max_count , x.second);
        
        vector<bool> check(max_count+1 , false);
        
        for(auto x : ump)
        {
            if(check[x.second] != false)
                return false;
            check[x.second] = true;
        }
        return true;
        
    }
};