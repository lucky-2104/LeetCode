class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int count = 0;
        count = numBottles;
        int filled = numBottles / numExchange;
        while(filled != 0)
        {
            int empty =  numBottles % numExchange;
            filled = numBottles / numExchange;
            numBottles = filled + empty;
            count = count + filled;
        }
        return count;
        
    }
};