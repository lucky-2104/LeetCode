//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfs(int s , vector<int> adj[] , int V)
    {
        vector<int> bfs ;
        vector<int> vis(V , 0);
        queue<int> q;
        
        vis[s] = 1;
        q.push(s);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();bfs.push_back(node);
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
    }
    
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        for(int i = 0 ; i < V ; i++)
        {
            return bfs(i , adj , V);
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends