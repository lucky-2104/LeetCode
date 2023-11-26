class Solution {
public:
    
    void bfs(int i , int j , vector<vector<int>>&visited ,vector<vector<int>>&grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int , int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        while(!q.empty())
        {
            int row = q.front().first , col = q.front().second;
            q.pop();
            
            if(row > 0 and visited[row-1][col] == 0 and grid[row-1][col] == 1 ){
                q.push({row-1,col});
                visited[row-1][col] = 1;
            }
            if(row < m-1 and visited[row+1][col] == 0 and grid[row+1][col] == 1 ){
                q.push({row+1,col});
                visited[row+1][col] = 1;
            }
            if(col > 0 and visited[row][col-1] == 0 and grid[row][col-1] == 1 ){
                q.push({row,col-1});
                visited[row][col-1] = 1;
            }
            if(col < n-1 and visited[row][col+1] == 0 and grid[row][col+1] == 1 ){
                q.push({row,col+1});
                visited[row][col+1] = 1;
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int count1 = 0;
        int m = grid.size() , n = grid[0].size();
        
        
        vector<vector<int>> visited(m , vector<int>(n,0));
        
        for(int i = 0; i < n ; i++)
        {
            if(grid[0][i] == 1 and !visited[0][i])
                bfs(0,i,visited,grid);
        }
        for(int i = 0 ; i < m ; i++)
        {
            if( grid[i][0] == 1 and !visited[i][0])
                bfs(i,0,visited , grid);
        }
        for(int i = 0 ; i < n ; i++)
        {
            if( grid[m-1][i] == 1 and !visited[m-1][i])
                bfs(m-1,i,visited , grid);
        }
        for(int i = 0 ; i < m ; i++)
        {
            if(grid[i][n-1] == 1 and !visited[i][n-1])
            {
                bfs(i,n-1,visited , grid);
            }
                
        }
        
        int count = 0;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {  
                 if(grid[i][j] == !visited[i][j])
                     count++;
            }
        }
        
        return count;
    }
};