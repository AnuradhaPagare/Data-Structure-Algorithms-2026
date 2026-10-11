class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string result = "";
        string hex = "0123456789abcdef";

        unsigned int value = num;

        while (value > 0) {
            int digit = value & 15;
            result += hex[digit];
            value >>= 4;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};