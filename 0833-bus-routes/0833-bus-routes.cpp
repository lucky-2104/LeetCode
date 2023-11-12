class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> route_conn;

        for(int i = 0 ; i < routes.size() ; i++)
        {
            for(auto x : routes[i])
            route_conn[x].insert(i);
        }

        queue<pair<int,int>> to_visit;
        to_visit.push({source,0});
        unordered_set<int> visited(source);

        while(!to_visit.empty())
        {
            int stop = to_visit.front().first;
            int bus_num = to_visit.front().second;
            to_visit.pop();

            if(target == stop) return bus_num;

            for(auto route : route_conn[stop])
            {
                for(auto next_stop : routes[route])
                {
                    auto it = visited.insert(next_stop);
                    if (it.second)
                    to_visit.push({next_stop , bus_num+1});
                }

                routes[route].clear();

            }
        }
        return -1;
        
    }
};