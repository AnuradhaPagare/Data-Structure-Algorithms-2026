class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        bool is_ascending = true;
        bool is_descending = true;
        int idx = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
            }
            
            int next_idx = (i + 1) % n;
            int next_val_asc = (nums[i] + 1) % n;
            int next_val_desc = (nums[i] - 1 + n) % n;

            if (nums[next_idx] != next_val_asc) {
                is_ascending = false;
            }
            if (nums[next_idx] != next_val_desc) {
                is_descending = false;
            }
        }

        if (!is_ascending && !is_descending) {
            return -1;
        }

        if (is_ascending) {
            return min(idx, 2 + n - idx);
        } else {
            int option1 = 1 + ((idx + 1) % n);
            int option2 = 1 + (n - 1 - idx);
            return min(option1, option2);
        }
    }
};
