class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        for (char c : columnTitle) {
            // Convert character to its 1-indexed value (A=1, B=2, etc.)
            int d = c - 'A' + 1;
            // Shift the accumulated result by base 26 and add the new digit
            result = result * 26 + d;
        }
        return result;
    }
};
