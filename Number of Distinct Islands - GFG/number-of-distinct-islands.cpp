//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    vector<int>  bfs(int i , int j , vector<vector<int>>& visited , vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> temp;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        int row_base = i , col_base = j;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            temp.push_back(row_base-row);
            temp.push_back(col_base-col);
            
            q.pop();
            
            if(row > 0 and !visited[row-1][col] and grid[row-1][col] == 1)
            {
                q.push({row-1,col});
                visited[row-1][col] = 1;
            }
            
            if(row < m-1 and !visited[row+1][col] and grid[row+1][col] == 1)
            {
                q.push({row+1,col});
                visited[row+1][col] = 1;
            }
            
            if(col > 0 and !visited[row][col-1] and grid[row][col-1] == 1)
            {
                q.push({row,col-1});
                visited[row][col-1] = 1;
            }
            
            if(col < n-1 and !visited[row][col+1] and grid[row][col+1] == 1)
            {
                q.push({row,col+1});
                visited[row][col+1] = 1;
            }
            
        }
        return temp;
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<vector<int>> st;
        
        vector<vector<int>> visited(m , vector<int>(n,0));
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(!visited[i][j] and grid[i][j] == 1)
                {
                    vector<int>temp = bfs(i,j,visited,grid);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
        
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends