class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long current_cost = 0;
        deque<pair<long long, int>> dq;
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            long long val = nums[l];
            int count = 1;
            
            while (!dq.empty() && dq.back().first <= val) {
                auto [prev_val, prev_cnt] = dq.back();
                dq.pop_back();
                current_cost += (val - prev_val) * prev_cnt;
                count += prev_cnt;
            }
            dq.push_back({val, count});
            
            while (current_cost > k) {
                auto& [front_val, front_cnt] = dq.front();
                current_cost -= (front_val - nums[r]);
                --front_cnt;
                if (front_cnt == 0) {
                    dq.pop_front();
                }
                --r;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
