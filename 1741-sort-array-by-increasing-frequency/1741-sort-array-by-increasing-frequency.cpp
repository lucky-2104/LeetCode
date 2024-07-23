class Solution {
public:
struct mycmp{
    bool operator()(pair<int,int> f1 , pair<int,int> f2)
    {
        if(f1.second > f2.second)
            return true;
        if(f1.second == f2.second and f1.first < f2.first)
            return true;
        return false;
    }
};
    vector<int> frequencySort(vector<int>& nums) {
        

        map<int,int> mp;
        
        for(int i = 0 ; i < nums.size() ;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , mycmp> pq;
        
        for(auto x : mp)
        {
            pq.push(x);
        }
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            int n = pq.top().second;
            while(n){
                ans.push_back(pq.top().first);
                n--;
            }
            pq.pop();
        }
        
        return ans;
        
        
        
    }
};