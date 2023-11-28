class Solution {
public:
    int numberOfWays(string corridor) {
        int M = 1e9 + 7;
        vector<int> seat_number;
        // Find Seat Indices
        for(int i = 0; i < corridor.size(); i++) {
            if(corridor[i] == 'S')
                seat_number.push_back(i);
        }
        // check Seats are Odd or Zero
        if(seat_number.size() % 2 != 0 || seat_number.size() == 0)
            return 0;
        // Computing the result
        long long int result = 1;
        for(int i = 2; i < seat_number.size(); i += 2) {
            result =( result * (seat_number[i] - seat_number[i-1]) % M);
        }
        return result;
    }
};