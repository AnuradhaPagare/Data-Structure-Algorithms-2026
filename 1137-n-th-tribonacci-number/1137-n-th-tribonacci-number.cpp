class Solution {
public:
    int tribonacci(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Initialize the first three numbers of the sequence
        int t0 = 0, t1 = 1, t2 = 1;
        int next_t = 0;
        
        // Iteratively compute up to n
        for (int i = 3; i <= n; ++i) {
            next_t = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = next_t;
        }
        
        return t2;
    }
};
