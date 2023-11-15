class Solution {
public:


    void dfs(int s , vector<vector<int>>& graph , vector<int>& visited)
    {
        visited[s] = 1;

        for(int i = 0 ; i < graph[0].size() ; i++)
        {
            if(graph[s][i] == 1 and !visited[i])
            {
                dfs(i , graph , visited);
            }
        } 
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n ,0);
        int provinces = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(i , isConnected , visited);
            }
        }
        return provinces;
        
    }
};