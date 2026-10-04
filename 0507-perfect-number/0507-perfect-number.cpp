class Solution {
public:
    bool checkPerfectNumber(int num) {
        // Perfect numbers must be greater than 1
        if (num <= 1) {
            return false;
        }
        
        int sum = 1; // 1 is always a divisor for any number > 1
        
        // Find divisors up to the square root of num
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                // If the divisors are distinct, add the matching divisor
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        
        return sum == num;
    }
};
