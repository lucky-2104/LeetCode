class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue <int, vector<int>, greater<int>> gq;
       int i = 0;
       while(i < k)
       {
           gq.push(nums[i++]);
       }
       while(i < nums.size())
       {
           if(gq.top() < nums[i])
           {
               gq.pop();
               gq.push(nums[i]);
           }
           i++;
       }
       return gq.top();  
    }
};