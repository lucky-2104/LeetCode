class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int p = (minutesToTest / minutesToDie + 1);
        return int(ceil(log10(buckets)/log10(p)));
        
    }
};