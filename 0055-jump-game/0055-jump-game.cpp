class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is unreachable, we cannot move forward
            if (i > maxReach) {
                return false;
            }
            
            // Update the maximum reachable index from the current position
            maxReach = max(maxReach, i + nums[i]);
            
            // Optimization: If we can already reach the last index, return true early
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
