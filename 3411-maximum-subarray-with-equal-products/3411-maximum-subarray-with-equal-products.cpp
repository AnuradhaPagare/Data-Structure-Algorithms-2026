class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        long long maxLimit = 25200; 

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int currentGcd = 0;
            int currentLcm = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                
                if (prod > maxLimit) {
                    break;
                }

                currentGcd = gcd(currentGcd, nums[j]);
                currentLcm = lcm(currentLcm, nums[j]);

                if (prod == 1LL * currentLcm * currentGcd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
