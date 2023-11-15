class Solution {
public:

    void dfs(int s,int s2,vector<vector<char>>& graph , vector<vector<int>>& visited)
    {
        visited[s][s2] = 1;
        if(s > 0 and !visited[s-1][s2] and  graph[s-1][s2] == '1')
        dfs(s-1 , s2 , graph , visited);
        if(s < graph.size()-1 and !visited[s+1][s2]  and graph[s+1][s2] == '1')
        dfs(s+1 , s2 , graph , visited);
        if(s2 > 0 and !visited[s][s2-1] and graph[s][s2-1] == '1')
        dfs(s , s2-1 , graph , visited);
        if(s2 < graph[0].size()-1 and !visited[s][s2+1] and graph[s][s2+1]== '1')
        dfs(s , s2+1 , graph , visited);
    }


    int numIslands(vector<vector<char>>& grid) {

        //Can be easily done by BFS algorithm
        int count = 0;

        vector<vector<int>> visited(grid.size() , vector<int>(grid[0].size() , 0));
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == '1' and !visited[i][j])
                {   
                    cout <<i << j <<  " " << endl;
                    dfs(i , j , grid , visited);
                    count++;
                }
            } 
        }
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                cout << visited[i][j] << " ";
            } 
            cout << endl;
        }        
        return count;


        
    }
};