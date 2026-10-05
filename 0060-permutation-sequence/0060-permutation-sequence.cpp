#include <string>
#include <vector>

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n); 
        
        string result = "";
        k = k - 1; 
        
        while (true) {
            int index = k / fact;
            result += to_string(numbers[index]);
            
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) {
                break;
            }
            
            k %= fact;
            fact /= numbers.size();
        }
        
        return result;
    }
};
