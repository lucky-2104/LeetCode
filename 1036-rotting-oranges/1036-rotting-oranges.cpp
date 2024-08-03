class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        int m = grid.size() , n = grid[0].size();
        for(int i = 0 ; i < m ;i++)
        {
            for(int j = 0 ; j < n ;j++)
            if(grid[i][j] == 2) pq.push({0,{i,j}});
        }
        int time = 0;

        while(!pq.empty())
        {
            int curr_time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row+1 < m and grid[row+1][col] == 1)
            {
                pq.push({curr_time+1,{row+1,col}});
                grid[row+1][col] = 2;
            }
            if(row - 1 >= 0 and grid[row-1][col] == 1)
            {
                pq.push({curr_time+1 ,{row-1,col}});
                grid[row-1][col] = 2;
            }
            if(col+1 < n and grid[row][col+1] == 1)
            {
                pq.push({curr_time+1,{row,col+1}});
                grid[row][col+1] = 2;
            }
            if(col - 1 >= 0 and grid[row][col-1] == 1)
            {
                pq.push({curr_time+1 ,{row,col-1}});
                grid[row][col-1] = 2;
            }
            time = curr_time;
        }

        for(int i = 0 ; i < m ;i++)
        {
            for(int j = 0 ; j < n ;j++)
            if(grid[i][j] == 1) return -1;
        }

        return time;


        
    }
};