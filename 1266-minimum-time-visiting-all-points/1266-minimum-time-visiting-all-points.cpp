class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points){
        
        int distance = 0;
        
        int x1 = points[0][0];
        int y1 = points[0][1];
        
        for(int i = 1 ; i < points.size() ; i++)
        {
            distance = distance + max(abs(points[i][0]-x1) , abs(points[i][1]-y1));
            x1 = points[i][0];
            y1 = points[i][1]; 
        }
        
        return distance;
        
        
        
    }
};