class Solution {
public:
    int hammingDistance(int x, int y) {
        // x ^ y isolates the differing bits
        // __builtin_popcount counts the total number of set bits (1s)
        return __builtin_popcount(x ^ y);
    }
};
