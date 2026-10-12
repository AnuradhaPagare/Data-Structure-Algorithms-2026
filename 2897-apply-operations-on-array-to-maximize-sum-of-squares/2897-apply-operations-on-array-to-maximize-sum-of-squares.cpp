class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       
        vector<int> bitCounts(31, 0);
        for (int num : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((num >> i) & 1) {
                    bitCounts[i]++;
                }
            }
        }
        
        long long totalSumOfSquares = 0;
        long long MOD = 1e9 + 7;
        
        for (int j = 0; j < k; ++j) {
            long long currentNum = 0;
            for (int i = 0; i < 31; ++i) {
                if (bitCounts[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCounts[i]--; // Consume one bit
                }
            }
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSumOfSquares;
    }
};
