class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses , 0);
        vector<vector<int>> graph;

        for(int i = 0 ; i < numCourses ;i++)
        {
            graph.push_back({});
        } 

        for(int i = 0 ;i < prerequisites.size() ; i++){
            indegree[prerequisites[i][1]]++;
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

        }

        vector<int> order;
        queue<int> q;

        for(int i = 0 ;i < indegree.size() ; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto x: graph[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                q.push(x);
            }
        }
        if(order.size() != numCourses)
        return {};
        reverse(order.begin() , order.end());
        return order;
     
    }
};