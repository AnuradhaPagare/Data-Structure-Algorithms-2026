class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 1500;
        
        vector<int> freq(max_factor + 1, 0);
        int min_price = 1501;
        
        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }
        
        vector<int> free_items(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (freq[f] > 0) {
                int count = freq[f] - 1; 
                for (int multiple = 2 * f; multiple <= max_factor; multiple += f) {
                    count += freq[multiple];
                }
                free_items[f] = count;
            }
        }
        
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            int p = items[i][1];
            int val = 1 + free_items[f];
            
            for (int c = budget; c >= p; --c) {
                if (dp[c - p] != -1) {
                    dp[c] = max(dp[c], dp[c - p] + val);
                }
            }
        }
        
        int ans = 0;
        for (int c = 0; c <= budget; ++c) {
            if (dp[c] != -1) {
                int extra_copies = (budget - c) / min_price;
                ans = max(ans, dp[c] + extra_copies);
            }
        }
        
        return ans;
    }
};
