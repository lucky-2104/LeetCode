class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0,white = 0,blue = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0)red++;
            if(nums[i] == 1)white++;
            if(nums[i] == 2)blue++;
        }
        int k = 0;
        while(red--)nums[k++]=0;
        while(white--)nums[k++]=1;
        while(blue--)nums[k++]=2;
    }
};