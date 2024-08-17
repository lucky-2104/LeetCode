class Solution {
public:

    int parentfind(vector<int>& parent  , int node)
    {
        if(parent[node] == node)
        return node;

        return parent[node] = parentfind(parent , parent[node]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<int> rank(n,0);
        vector<int> parent(n,0);
        int edges_used = 0;
        int ans = connections.size();

        for(int i =  0 ; i < n ; i++) parent[i] = i;

        for(int i = 0 ; i < connections.size() ; i++)
        {
            int n1 = connections[i][0];
            int n2 = connections[i][1];


            int parent_n1 = parentfind(parent , n1);
            int parent_n2 = parentfind(parent , n2);

            if(parent_n1 != parent_n2)
            {
                if(rank[parent_n1] < rank[parent_n2])
                {
                    parent[parent_n1] = parent_n2;
                }
                else if(rank[parent_n2] < rank[parent_n1])
                {
                    parent[parent_n2] = parent_n1;
                }
                else{
                    parent[parent_n1] = parent_n2;
                    rank[parent_n1]++;
                }
                ans = ans -1;
                edges_used++;
            }
        }
        int vertices = edges_used+1;

        if(n - vertices > ans)
        return -1;

        return n-vertices;
        
    }
};