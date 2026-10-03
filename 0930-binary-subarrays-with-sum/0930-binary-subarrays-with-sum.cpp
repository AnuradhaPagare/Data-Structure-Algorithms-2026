#include <vector>

class Solution {
private:
    // Helper function to count subarrays with a sum less than or equal to 'goal'
    int countAtMost(const std::vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0;
        int currentSum = 0;
        int count = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];
            
            // Shrink the window from the left if the sum exceeds the goal
            while (currentSum > goal) {
                currentSum -= nums[left];
                left++;
            }
            
            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            count += (right - left + 1);
        }
        
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};
