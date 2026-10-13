class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        long long max_score = 0;
        int n = nums.size();
        int mid = n / 2;

        for (int i = 0; i < mid; i++) {
            max_score -= (long long)nums[i] * nums[i];
        }
        for (int i = mid; i < n; i++) {
            max_score += (long long)nums[i] * nums[i];
        }

        return max_score;
    }
};
