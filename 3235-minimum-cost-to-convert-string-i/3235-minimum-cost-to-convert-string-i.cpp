class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {


        vector<vector<int>> distance(26 , vector<int>(26,INT_MAX));
        int siz = original.size();

        for(int i = 0 ; i < siz;i++)
        {
            int row = original[i] - 'a';
            int col = changed[i] -'a';
            distance[row][col] = min(distance[row][col] , cost[i]);
        }


        for(int i = 0 ; i < 26 ; i++) distance[i][i] = 0;


        for(int k = 0 ; k < 26 ;k++)
            for(int i = 0 ; i < 26 ; i++)
                for(int j = 0 ; j < 26 ;j++)
                    distance[i][j] = min((long long)distance[i][j] , (long long)distance[i][k] + distance[k][j]);    
        
        long long ans = 0;
        for(int i = 0 ; i < source.size() ;i++)
        {
            int row = source[i] -'a';
            int col = target[i] - 'a';
            if(distance[row][col] == INT_MAX) return -1; 
            ans = ans + distance[row][col];
        }   
        return ans; 
    }
};