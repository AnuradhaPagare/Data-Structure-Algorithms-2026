class Solution {
public:
    bool isUgly(int n) {
        // Ugly numbers must be positive integers
        if (n <= 0) return false;
        
        // Divide by 2, 3, and 5 as much as possible
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        
        // If it reduces to 1, it's an ugly number
        return n == 1;
    }
};
