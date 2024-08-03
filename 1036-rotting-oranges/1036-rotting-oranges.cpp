class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> rotten_tomatoes;
        
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                rotten_tomatoes.push({i,j});
            }
        }
        
        rotten_tomatoes.push({-1,-1});
        int count = 0;
        
        while(rotten_tomatoes.size() > 1)
        {
            auto x = rotten_tomatoes.front();
            int i = x.first;
            int j = x.second;
            rotten_tomatoes.pop();
            
            if(i == -1 and j == -1)
            {
                count++;
                rotten_tomatoes.push({-1,-1});
            }
            
            if(i > 0 and grid[i-1][j] == 1)
            {
                grid[i-1][j] = 2;
                rotten_tomatoes.push({i-1,j});
            }   
            if(i < grid.size()-1 and grid[i+1][j] == 1)
            {
                grid[i+1][j] = 2;
                rotten_tomatoes.push({i+1,j});
            }
            if(j > 0 and grid[i][j-1] == 1)
            {
                grid[i][j-1] = 2;
                rotten_tomatoes.push({i,j-1});
            }
            if(j < grid[0].size()-1 and grid[i][j+1] == 1)
            {
                grid[i][j+1] = 2;
                rotten_tomatoes.push({i,j+1});
            }            
            
        }
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }        
        return count;
        
    }
};