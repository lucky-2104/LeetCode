//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int s , int v , vector<int> adj[] , vector<int>& visited , vector<int>& dfs_traversal)
    {
        visited[s] = 1;
        dfs_traversal.push_back(s);
        
        // std::cout << s << endl;
        
        for(auto it : adj[s])
        {
            if(!visited[it])
            {
                dfs(it , v , adj , visited , dfs_traversal );
            }
        }
        
        
        
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> visited(V , 0);
        vector<int> dfs_traversal;
        
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            dfs(i , V , adj , visited,dfs_traversal);
        }
        return dfs_traversal;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends