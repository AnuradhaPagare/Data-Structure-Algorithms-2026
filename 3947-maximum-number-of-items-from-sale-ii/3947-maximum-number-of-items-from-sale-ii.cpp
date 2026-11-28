class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        int min_price = 2e9;

        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }

        vector<int> max_free(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (freq[f] == 0) continue;
            int count = 0;
            for (int mult = f; mult <= n; mult += f) {
                count += freq[mult];
            }
            max_free[f] = count - 1;
        }

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long rem_budget = budget;
        long long total_items = 0;

        for (const auto& item : items) {
            long long price = item[1];
            if (price >= 2LL * min_price) {
                break;
            }

            long long available_deals = max_free[item[0]];
            if (available_deals > 0 && rem_budget >= price) {
                long long can_buy = min(available_deals, rem_budget / price);
                total_items += can_buy * 2;
                rem_budget -= can_buy * price;
            }
        }

        total_items += rem_budget / min_price;

        return static_cast<int>(total_items);
    }
};
