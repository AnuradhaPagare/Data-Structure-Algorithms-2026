// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            // Prevents potential integer overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // mid could be the first bad version, or the first bad version is to its left
                right = mid;
            } else {
                // mid is good, so the first bad version must be to its right
                left = mid + 1;
            }
        }
        
        // When left == right, we have found the first bad version
        return left;
    }
};
