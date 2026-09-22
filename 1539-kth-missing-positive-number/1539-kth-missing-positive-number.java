class Solution {
    public int findKthPositive(int[] arr, int k) {
        int low = 0;
        int high = arr.length - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Calculate how many positive integers are missing before arr[mid]
            int missingCount = arr[mid] - (mid + 1);
            
            if (missingCount < k) {
                low = mid + 1; // Look in the right half
            } else {
                high = mid - 1; // Look in the left half
            }
        }
        
        // At the end of the loop, low is the correct insertion index.
        // The kth missing number is low + k.
        return low + k;
    }
}
