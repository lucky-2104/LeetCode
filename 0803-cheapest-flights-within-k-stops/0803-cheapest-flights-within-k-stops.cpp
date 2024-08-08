class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n , INT_MAX);

        vector<vector<pair<int,int>>> graph;

        for(int i = 0 ; i < n ; i++) graph.push_back({});

        for(auto itr : flights)
        {
            int src = itr[0] , dest = itr[1] , cost = itr[2];
            graph[src].push_back({dest,cost});
        }

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;


        pq.push({0,{src,0}});

        while(!pq.empty()){
            int stop = pq.top().first;
            int node = pq.top().second.first;
            int cost = pq.top().second.second;

            pq.pop();

            if(stop > k)
            continue;

            for(auto itr : graph[node]){
                int adjNode = itr.first;
                int wt = itr.second;
                if(cost + wt < dist[adjNode] and stop <= k)
                {
                    dist[adjNode] = cost+wt;
                    pq.push({stop+1,{adjNode,cost+wt}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
        return -1;

        return dist[dst];

        
    }
};
