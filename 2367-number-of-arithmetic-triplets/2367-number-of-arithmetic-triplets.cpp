class Solution {
public:
    int arithmeticTriplets(std::vector<int>& nums, int diff) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int count = 0;
        
        for (int x : nums) {
            if (num_set.count(x - diff) && num_set.count(x + diff)) {
                count++;
            }
        }
        
        return count;
    }
};