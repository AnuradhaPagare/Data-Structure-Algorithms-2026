class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0;
        string result = "";
        int n = s.size();

        for(int i = n - 1; i >= 0; --i){
            if(s[i] != '-'){
                if(count > 0 && count % k == 0){
                    result += '-';
                }
                result += toupper(s[i]);
                count++;
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};