class Solution {
public:

    void dfs(vector<vector<int>>& isConnected , int node , vector<int>& visited,int n)
    {
        visited[node] = 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i] and isConnected[node][i] == 1)
            dfs(isConnected , i , visited , n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int provinces = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);

        for(int i = 0 ; i < isConnected.size() ;i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(isConnected , i , visited ,n);
            }

        }
        return provinces;

        
    }
};