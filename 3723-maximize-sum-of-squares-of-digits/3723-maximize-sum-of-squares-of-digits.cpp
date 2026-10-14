class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * (long long)num || sum < 1) {
            return "";
        }
        
        string result = "";
        
        for (int i = 0; i < num; ++i) {
            int remaining_digits = num - 1 - i;
            
            for (int d = 9; d >= 0; --d) {
                if (i == 0 && d == 0) continue;
                if (d > sum) continue;
                
                if (sum - d <= remaining_digits * 9) {
                    result += to_string(d);
                    sum -= d;
                    break;
                }
            }
        }
        
        return result;
    }
};
