class Solution {
public:
    std::vector<int> findCoins(std::vector<int>& numWays) {
        int n = numWays.size();
        
        // dp[i] tracks the simulated ways to form amount i using currently discovered coins
        // We use long long to safely avoid any overflow constraints during accumulation
        std::vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: 1 way to make amount 0 (using no coins)

        std::vector<int> resultCoins;

        // Iterate through each target amount from 1 to n greedily
        for (int i = 1; i <= n; i++) {
            long long targetWays = numWays[i - 1]; // numWays is 0-indexed in the input

            // Case 1: Our simulated ways perfectly match the target.
            if (dp[i] == targetWays) {
                continue;
            } 
            // Case 2: We need more ways, meaning a new coin of value 'i' must be added.
            else if (dp[i] < targetWays) {
                // A new unique coin of value 'i' can only contribute exactly 1 new path 
                // to its own index (dp[i] = dp[i] + dp[0], and dp[0] is 1).
                // If the gap is greater than 1, this configuration is invalid.
                if (targetWays - dp[i] != 1) {
                    return {};
                }

                // Add the coin to our solution
                resultCoins.push_back(i);

                // Instantly update the DP table with this new coin for all subsequent amounts
                for (int j = i; j <= n; j++) {
                    dp[j] += dp[j - i];
                }
            } 
            // Case 3: We have already exceeded the target ways. It's impossible to correct.
            else {
                return {};
            }
        }

        return resultCoins;
    }
};