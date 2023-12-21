class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        vector<int> xaxis;
        
        for(int i =0 ; i < points.size() ; i++)
        {
            xaxis.push_back(points[i][0]);
        }
        
        sort(xaxis.begin() , xaxis.end());
        
        int count = xaxis[1] - xaxis[0];
        
        for(int i = 2 ; i < xaxis.size() ; i++)
        {
            if(count < xaxis[i] - xaxis[i-1])
                count = xaxis[i] - xaxis[i-1];
        }
        return count;
        
    }
};