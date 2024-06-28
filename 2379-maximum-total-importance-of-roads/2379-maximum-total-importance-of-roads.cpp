class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        
        vector<pair<long , long>> assign;

        

        vector<long long> degree(n,0);

        for(auto itr : roads)
        {
            long long src = itr[0];
            long long dest = itr[1];

            degree[src]++;
            degree[dest]++;

        }

        for(int i = 0 ; i < n ; i++)
        {
            assign.push_back({degree[i],i});
        }

        sort(assign.rbegin(),assign.rend());

        for(auto itr : assign)
        {
            cout << itr.first << " " << itr.second << endl;
        }

        vector<long> numbering(n,0);
        long long k = n;
        for(int i = 0 ; i < assign.size() ; i++)
        {
            numbering[assign[i].second] = k--;
        }

        long long count = 0;
        for(auto itr : roads)
        {
            int x = itr[0] , y = itr[1];
            count = count + numbering[x]  + numbering[y];
        }

        return count;

        
    }
};