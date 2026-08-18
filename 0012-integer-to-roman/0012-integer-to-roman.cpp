#include <string>
#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        // Map of Roman numeral values and their corresponding symbols in descending order
        const vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        // Loop through all values
        for (size_t i = 0; i < values.size(); ++i) {
            // While the current value can fit into num, append symbol and subtract value
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};
