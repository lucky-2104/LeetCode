class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;
        int i = 0 , j = 0;
        s.insert({0,0});
        for(auto x : path)
        {
            
            if(x == 'N')
            j++;
            else if(x == 'S')
            j--;
            else if(x == 'E')
            i++;
            else
            i--;
            
            s.insert({i,j});
        }
        cout << s.size() << path.size() << endl;
        if(s.size() == path.size()+1)
            return false;
        return true;
    }
};