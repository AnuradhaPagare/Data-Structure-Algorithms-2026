class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<long long> counts(100001, 0);
        long long max_diff = 0;

        for (int i = 0; i < n; ++i) {
            long long diff = abs(nums1[i] - nums2[i]);
            counts[diff]++;
            max_diff = max(max_diff, diff);
        }

        for (long long d = max_diff; d > 0; --d) {
            if (counts[d] == 0) continue;
            
            long long take = min(k, counts[d]);
            counts[d] -= take;
            counts[d - 1] += take;
            k -= take;

            if (k == 0) break;
        }

        long long ans = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (counts[d] > 0) {
                ans += counts[d] * d * d;
            }
        }

        return ans;
    }
};
