class Solution {
const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {

        std::sort(arr.begin(), arr.end());
        

        std::unordered_set<int> uniqueNumbers(arr.begin(), arr.end());
  
        std::unordered_map<int, int> dp;
        for (int num : arr) {
            dp[num] = 1;
        }
        
        for (int i : arr) {
            for (int j : arr) {

                if (j > std::sqrt(i)) break;
                
        
                if (i % j == 0 && uniqueNumbers.find(i / j) != uniqueNumbers.end()) {
                    long long temp = static_cast<long long>(dp[j]) * dp[i / j];
                    
         
                    if (i / j == j) {
                        dp[i] = (dp[i] + temp) % MOD;
                    } else {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }
        
        int result = 0;
        for (auto& [_, val] : dp) {
            result = (result + val) % MOD;
        }
        return result;
    }
};