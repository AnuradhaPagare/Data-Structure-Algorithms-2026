class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digit_sum = 0;
        int digit_product = 1;

        // Extract each digit to calculate sum and product
        while (temp > 0) {
            int digit = temp % 10;
            digit_sum += digit;
            digit_product *= digit;
            temp /= 10;
        }

        // Calculate the total combined divisor
        int divisor = digit_sum + digit_product;

        // Check if n is perfectly divisible by the divisor
        return (n % divisor == 0);
    }
};
