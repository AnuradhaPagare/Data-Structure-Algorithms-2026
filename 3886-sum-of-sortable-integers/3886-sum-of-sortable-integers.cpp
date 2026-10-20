class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        
        int total_sum = 0;
        
        for (int k : divisors) {
            bool is_valid = true;
            
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int drop_idx = -1;
                
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k];
                    if (curr > next) {
                        drops++;
                        drop_idx = j;
                    }
                }
                
                if (drops > 1) {
                    is_valid = false;
                    break;
                }
                
                int start_j = (drops == 0) ? 0 : (drop_idx + 1) % k;
                
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (start_j + j) % k] != sorted_nums[i + j]) {
                        is_valid = false;
                        break;
                    }
                }
                
                if (!is_valid) break;
            }
            
            if (is_valid) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};
