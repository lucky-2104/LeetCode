class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int max_25 = floor(0.25 * arr.size());
        
        int count = 1;
        int curr = arr[0];
        for(int i = 1 ;i < arr.size();i++)
        {
            if(arr[i] == curr)
                count++;
            else if(arr[i] != curr)
            {
                count = 1;
                curr = arr[i];
            }
            if(count > max_25)
                return curr;
        }
        return curr;
        
        
    }
};