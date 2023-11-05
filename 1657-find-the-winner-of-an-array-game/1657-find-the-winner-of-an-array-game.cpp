class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int prev = 0;
        int curr = arr[0];
        int count = 0;
        for(int i = 1 ; i < arr.size() ; i++)
        {
            if(count == k)
            return curr;

            if(arr[i] < curr)
            count++;

            if(arr[i] > curr)
            {
                prev = curr;
                curr = arr[i];
                count = 1;
            }
        }
        return curr;
        
    }
};