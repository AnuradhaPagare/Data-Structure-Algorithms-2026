class Solution {
public:
    string convertToBase7(int num) {

        if(num == 0){
            return "0";
        }

        bool isNegative = num < 0;
        long long temp = abs((long long)num);
        string result = "";

        while(temp > 0){
            int remainder = temp % 7;
            temp /= 7;
            result += to_string(remainder);
        }

        if(isNegative){
            result += "-";
        }
        reverse(result.begin(), result.end());

        return result;
    }
};