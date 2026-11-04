class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> leftHalf, rightHalf;
        long long leftSum = 0, rightSum = 0;

        auto balance = [&]() {
            while (leftHalf.size() > rightHalf.size() + 1) {
                int value = *leftHalf.rbegin();

                leftHalf.erase(leftHalf.find(value));
                leftSum -= value;

                rightHalf.insert(value);
                rightSum += value;
            }

            while (leftHalf.size() < rightHalf.size()) {
                int value = *rightHalf.begin();

                rightHalf.erase(rightHalf.find(value));
                rightSum -= value;

                leftHalf.insert(value);
                leftSum += value;
            }
        };

        auto add = [&](int value) {
            if (leftHalf.empty() || value <= *leftHalf.rbegin()) {
                leftHalf.insert(value);
                leftSum += value;
            } else {
                rightHalf.insert(value);
                rightSum += value;
            }

            balance();
        };

        auto remove = [&](int value) {
            if (leftHalf.find(value) != leftHalf.end()) {
                leftHalf.erase(leftHalf.find(value));
                leftSum -= value;
            } else {
                rightHalf.erase(rightHalf.find(value));
                rightSum -= value;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *leftHalf.rbegin();

            return median * leftHalf.size() - leftSum
                 + rightSum - median * rightHalf.size();
        };

        vector<long long> windowCost(n - x + 1);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        windowCost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            windowCost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {

                if (dp[j][i] == INF) {
                    continue;
                }

                // Skip current index
                dp[j][i + 1] = min(
                    dp[j][i + 1],
                    dp[j][i]
                );

                // Select a subarray of size x
                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] = min(
                        dp[j + 1][i + x],
                        dp[j][i] + windowCost[i]
                    );
                }
            }
        }

        return *min_element(dp[k].begin(), dp[k].end());
    }
};