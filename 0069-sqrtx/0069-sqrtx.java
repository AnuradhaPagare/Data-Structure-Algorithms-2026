class Solution {
    public int mySqrt(int x) {
        // Base case: the square root of 0 is 0, and 1 is 1
        if (x == 0 || x == 1) {
            return x;
        }

        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Equivalent to mid * mid <= x, but prevents integer overflow
            if (mid <= x / mid) {
                ans = mid;       // Store mid as a potential answer
                low = mid + 1;   // Try to find a larger integer
            } else {
                high = mid - 1;  // mid is too large, search the lower half
            }
        }

        return ans;
    }
}
