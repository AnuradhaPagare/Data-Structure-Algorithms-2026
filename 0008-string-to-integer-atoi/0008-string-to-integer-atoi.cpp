class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int digit = 0;
        int sign = 1;
        int i = 0;


        // whitespace handling
        while(i < n && s[i] == ' '){
            i++;
        }
        // minus sign handling
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

            while(i < n && s[i] >= '0' && s[i] <= '9'){
                int currentDigit = s[i] - '0';

                if((digit > INT_MAX / 10) || (digit == INT_MAX / 10 && currentDigit > INT_MAX %10)){
                    if(sign == 1){
                        return INT_MAX;
                    }else{
                        return INT_MIN;
                    }
                }
                digit = digit * 10 + currentDigit;
                i++;
            }
            // digit = 0 * 10 + (0 - '0');  0
            //digit = 0 * 10 + (4 - 0); 4
            //digit = 4 * 10 + (2 - 0); 42;

        
        return digit * sign;
    }
};