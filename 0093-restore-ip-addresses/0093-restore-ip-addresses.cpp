class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.length();
        
        if (n < 4 || n > 12) return result;
        
        for (int i = 1; i <= 3 && i < n; ++i) {
            for (int j = 1; j <= 3 && i + j < n; ++j) {
                for (int k = 1; k <= 3 && i + j + k < n; ++k) {
                    int l = n - i - j - k;
                    
                    if (l >= 1 && l <= 3) {
                        string s1 = s.substr(0, i);
                        string s2 = s.substr(i, j);
                        string s3 = s.substr(i + j, k);
                        string s4 = s.substr(i + j + k, l);
                        
                        if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                            result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                        }
                    }
                }
            }
        }
        return result;
    }

private:
    bool isValid(const string& str) {
        if (str.length() > 1 && str[0] == '0') return false;
        
        int num = stoi(str);
        return num >= 0 && num <= 255;
    }
};
