import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        // Sort the array to use the two-pointer technique
        Arrays.sort(nums);
        
        // Initialize the closest sum with the sum of the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Iterate through the array, fixing the first element of the triplet
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;
            
            // Use two pointers to find the best pair for the fixed element
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we find an exact match, return it immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // If the current sum is closer to the target than the previous closest sum, update it
                if (Math.abs(currentSum - target) < Math.abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on comparison with the target
                if (currentSum < target) {
                    left++; // We need a larger sum
                } else {
                    right--; // We need a smaller sum
                }
            }
        }
        
        return closestSum;
    }
}
