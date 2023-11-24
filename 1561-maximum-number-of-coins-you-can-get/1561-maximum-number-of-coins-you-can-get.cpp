class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n = piles.size() / 3;
        sort(piles.begin() , piles.end());
        int ind = piles.size() - 2;
        int ans = 0;
        for(int i = 0 ; i < n ;i++)
        {
            ans = ans + piles[ind];
            ind = ind - 2;
        }
        return ans;
        
    }
};