class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Powers of two must be strictly greater than 0
        // n & (n - 1) clears the lowest set bit. 
        // If it becomes 0, n was a power of two.
        return n > 0 && (n & (LLONG_MAX & (n - 1))) == 0;
    }
};
