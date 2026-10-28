class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> dp(n, vector<bool>(1024, false));
        
        dp[0][grid[0][0]] = true;
        
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            for (int v = 0; v < 1024; ++v) {
                if (dp[j - 1][v]) {
                    dp[j][v ^ val] = true;
                }
            }
        }
        
        for (int i = 1; i < m; ++i) {
            vector<vector<bool>> next_dp(n, vector<bool>(1024, false));
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                
                for (int v = 0; v < 1024; ++v) {
                    if (dp[j][v]) {
                        next_dp[j][v ^ val] = true;
                    }
                }
                
                if (j > 0) {
                    for (int v = 0; v < 1024; ++v) {
                        if (next_dp[j - 1][v]) {
                            next_dp[j][v ^ val] = true;
                        }
                    }
                }
            }
            dp = move(next_dp);
        }
        
        for (int v = 0; v < 1024; ++v) {
            if (dp[n - 1][v]) {
                return v;
            }
        }
        
        return 0;
    }
};
