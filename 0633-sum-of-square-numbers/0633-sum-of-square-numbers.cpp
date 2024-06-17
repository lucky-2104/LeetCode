class Solution {
public:
    bool judgeSquareSum(int c) {

        int upper = sqrt(c);

        int lower = 0;

        while(lower <= upper)
        {
            long long high = upper*upper;
            long long low = lower*lower;
            if(low + high < c)
            lower++;
            else if(low + high > c)
            upper--;
            else
            return true;
        }
        return false;
        
    }
};