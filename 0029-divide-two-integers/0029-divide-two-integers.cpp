#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the unique overflow condition specified in the constraints
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine if the final quotient should be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to negative numbers to prevent overflow
        int negDividend = dividend < 0 ? dividend : -dividend;
        int negDivisor = divisor < 0 ? divisor : -divisor;

        // Accumulate quotient as a negative number to avoid signed integer overflow
        int negQuotient = 0;

        // Since both numbers are negative, dividend <= divisor means 
        // the dividend has a larger magnitude (e.g., -10 <= -3)
        while (negDividend <= negDivisor) {
            int tempDivisor = negDivisor;
            int multiple = -1; // Keep tracking the units as negative values

            // Keep doubling the divisor as long as it doesn't exceed the dividend.
            // We use 'INT_MIN >> 1' instead of division to prevent bit overflow.
            while (tempDivisor >= (INT_MIN >> 1) && negDividend <= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the accumulated magnitude from the dividend
            negDividend -= tempDivisor;
            // Accumulate the quotient parts as a negative value
            negQuotient += multiple;
        }

        // If the result should be negative, return negQuotient as-is.
        // If positive, negate it. (Safely handles up to INT_MAX because negQuotient won't be INT_MIN here due to the early INT_MIN / -1 check).
        return isNegative ? negQuotient : -negQuotient;
    }
};
