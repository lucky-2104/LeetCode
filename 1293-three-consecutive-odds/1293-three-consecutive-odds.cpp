class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        bool value = false;
        if(arr.size() < 3)
        return value;

        for(int i = 0 ; i < arr.size()-2 ;i++)
        {
            if(arr[i]%2== 1 and arr[i+1]%2 ==1 and arr[i+2]%2 == 1)
            {
                value = true;
                break;
            }
        }
        return value;
        
    }
};