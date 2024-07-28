class Solution {
public:


    int convert(int stepsTaken , int change , int time)
    {
        int ans=0;
        for(int i=0; i < stepsTaken; i++) {
            int gr=ans/change;
            if (gr&1)  // If it's a red light
                ans=(gr+ 1)*change;
            ans+=time;
        }
        return ans;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> graph;

        for(int i = 0 ; i < n+1 ;i++) graph.push_back({});

        for(int i = 0 ; i < edges.size() ;i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        vector<int> dist(n+1 , INT_MAX);
        vector<int> dist2(n+1 , INT_MAX);
        queue<pair<int,int>>  q; //<node,distance>;

        q.push({1,0});

        while(!q.empty())
        {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();

            for(auto adjnode : graph[node])
            {
                int newdist = wt+1;
                if(newdist < dist[adjnode])
                {
                    dist2[adjnode] = dist[adjnode];
                    dist[adjnode] = newdist;
                    q.push({adjnode,newdist});
                }
                else if(newdist > dist[adjnode] && newdist < dist2[adjnode])
                {
                    dist2[adjnode] = newdist;
                    q.push({adjnode,newdist});
                }
            }
        }

        if(dist2[n] == INT_MAX) return -1;

        int result = convert(dist2[n] , change , time);
        return result;
    }
};