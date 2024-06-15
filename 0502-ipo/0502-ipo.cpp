class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        //Sort the array pick all the capitals smaller than w and insert them into max_priority_queue
        // and select the k element from that priority queue; and if selected increase the w by profit[i] and repeat
        //as soon as u increase the value of w

        vector<pair<int,int>> vec;
        for(int i = 0 ; i < profits.size() ; i++)   vec.push_back({capital[i] , profits[i]});

        sort(vec.begin() , vec.end());
        int count = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < vec.size() ; )
        {
            int cap = vec[i].first;
            int pro = vec[i].second;
            if(cap <= w)
            {
                pq.push({pro ,cap});
                i++;
            }
            else if(k > 0 and !pq.empty()){
                int curr_cap = pq.top().second;
                int curr_pro = pq.top().first;
                pq.pop();
                w = w + curr_pro;
                k--;
            }
            else
            break;
        }

        while(k > 0 and !pq.empty())
        {
            int curr_cap = pq.top().second;
            int curr_pro = pq.top().first;
            pq.pop();
            w = w + curr_pro;
            k--;
        }

        return w;
        
    }
};