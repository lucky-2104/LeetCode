class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx == fx and sy == fy)
        {
            if(t==1)
                return false;
            return true;
        }
        
        int ti = abs(sy - fy);
        int si = abs(sx-fx);
        
        int maxi = max(si,ti);
        if(maxi <= t)
            return true;
        else{
            return false;
        }
    }
};