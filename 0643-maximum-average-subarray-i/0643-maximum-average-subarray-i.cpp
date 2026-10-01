class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Base case: If the array has fewer elements than k, return 0 (or follow constraints)
        if (nums.size() < k) return 0;

        // Calculate the sum of the first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;
        
        // Slide the window across the rest of the array
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k]; // Add new element, remove old element
            maxSum = max(maxSum, windowSum);
        }
        
        // Convert to double to ensure precise floating-point division
        return (double)maxSum / k;
    }
};
