class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // Edge cases: target is out of bounds or subset sum cannot be a fraction
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) {
            return 0;
        }
        
        int subsetSum = (target + totalSum) / 2;
        
        // DP array to store the number of ways to reach each sum
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // Base case: 1 way to get a sum of 0 (empty subset)
        
        for (int num : nums) {
            for (int j = subsetSum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
};
