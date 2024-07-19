class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(grid.size() , vector<int>(grid[0].size() , INT_MAX));

        queue<pair<int,int>>q;

        if(grid[0][0] == 1) return -1;

        distance[0][0] = 1;

        
        q.push({0,0});

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            if(x+1 < n and grid[x+1][y] == 0 and distance[x][y]+1 < distance[x+1][y])
            {
                distance[x+1][y] = distance[x][y]+1; 
                q.push({x+1,y});

            }
            if(x-1 >= 0 and  grid[x-1][y] == 0 and distance[x][y]+1 < distance[x-1][y])
            {
                distance[x-1][y] = distance[x][y]+1; 
                q.push({x-1,y});

            }
            if(y+1 < m and  grid[x][y+1] == 0 and distance[x][y]+1 < distance[x][y+1])
            {
                distance[x][y+1] = distance[x][y]+1; 
                q.push({x,y+1});

            }
            if(y-1 >= 0 and  grid[x][y-1] == 0 and distance[x][y]+1 < distance[x][y-1])
            {
                distance[x][y-1] = distance[x][y]+1; 
                q.push({x,y-1});

            }

          
            if(x+1 < n and y+1 < m and  grid[x+1][y+1] == 0 and  distance[x][y] +1 < distance[x+1][y+1])
            {
                distance[x+1][y+1] = distance[x][y] +1;
                q.push({x+1,y+1});

            }

            if(x+1 < n and y-1 >= 0 and  grid[x+1][y-1] == 0 and distance[x][y] +1 < distance[x+1][y-1])
            {
                distance[x+1][y-1] = distance[x][y] +1;
                q.push({x+1,y-1});

            }

            if(x-1 >= 0 and y-1 >=0 and  grid[x-1][y-1] == 0  and distance[x][y] +1 < distance[x-1][y-1])
            {
                distance[x-1][y-1] = distance[x][y] +1;
                q.push({x-1,y-1});

            }

            if(x-1 >= 0 and y+1 < m and  grid[x-1][y+1] == 0 and distance[x][y] +1 < distance[x-1][y+1])
            {
                distance[x-1][y+1] = distance[x][y] +1;
                q.push({x-1,y+1});
            }
            q.pop();

        }


        if(distance[m-1][n-1] == INT_MAX) return -1;
        else
        return distance[m-1][n-1];
         
    

        
    }
};