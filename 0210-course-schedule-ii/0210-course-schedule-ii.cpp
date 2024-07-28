class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> graph;
        for(int i = 0 ; i < numCourses ;i++) graph.push_back({});

        vector<int> indegree(numCourses , 0);
        vector<int> ans;
        for(auto itr : prerequisites)
        { 
            graph[itr[0]].push_back(itr[1]);
            indegree[itr[1]]++;
        }

        //Toposort logic

        queue<int> q;
        for(int i = 0 ; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
            q.push(i);

        }
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto adjnode : graph[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        reverse(ans.begin() , ans.end());
        return ans;
     
    }
};