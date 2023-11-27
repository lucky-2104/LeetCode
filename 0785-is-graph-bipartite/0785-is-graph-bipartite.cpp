class Solution {
public:
    
    bool bfs(int s ,vector<vector<int>>& graph , vector<int>& colored , int color)
    {
        queue<pair<int,int>> q;
        
        colored[s] = color;
        q.push({s,color});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int prev_color = q.front().second;
            q.pop();
            
            for(auto x : graph[node])
            {
                if(colored[x] == -1)
                {
                    q.push({x , !prev_color});
                    colored[x] = !prev_color;
                }
                
                if(prev_color == colored[x])
                    return false;
            }
        }
        return true;
    
        
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> colored(graph.size() , -1);
        
        for(int i = 0 ; i < graph.size() ; i++)
        {
            if(colored[i] == -1)
            {
                if(bfs(i , graph , colored , 0) == false)
                    return false;
            }
        }
        return true;
        
    }
};