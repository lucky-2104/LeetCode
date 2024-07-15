class Solution {
public:

    int f(int i ,vector<int> &stairs)
    {
        if(i == 0)
        return 1;
        if(stairs[i] != -1)
        return stairs[i];

        int tookone = f(i-1 , stairs);
        int tooktwo = 0;
        if(i >= 2)
        tooktwo = f(i-2 , stairs);

        stairs[i] = tookone + tooktwo;
        return stairs[i];
    }

    int climbStairs(int n) { 

        vector<int> stair(n+1,-1);

        return f(n , stair);
        
    }
};