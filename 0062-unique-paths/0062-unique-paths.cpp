class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalSteps = m + n - 2;
        int k = min(m - 1, n - 1); 
        long long ans = 1;
        
        for (int i = 1; i <= k; i++) {
            ans = ans * (totalSteps - k + i) / i;
        }
        
        return (int)ans;
    }
};
