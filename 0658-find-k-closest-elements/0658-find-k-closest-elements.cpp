class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        
        priority_queue<pair<int ,int>> pq;
        int i = 0 ;
        while(i < k)
        {
            pq.push({abs(arr[i]-x) , arr[i]});
            i++;
        }
        while(i < arr.size())
        {
            int diff = abs(arr[i] - x);
            int large = pq.top().first;
            
            if(large > diff)
            { 
                pq.push(make_pair(diff,arr[i]));
                pq.pop();
            }
            i++;
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};