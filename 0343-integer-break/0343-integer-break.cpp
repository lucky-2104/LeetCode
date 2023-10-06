class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 or n == 3)
        return n-1;
        int count_3 = n /3 ;
        int rem = n%3;

        if(rem == 0)
        return pow(3,count_3);
        if(rem == 1)
        return pow(3,count_3-1)*4;
        else
        return pow(3,count_3)*2;


    }
};