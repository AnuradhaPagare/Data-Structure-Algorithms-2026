class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if (n <= 1) return "";
        
        // lps[i] will store the length of the longest happy prefix for substring s[0...i]
        vector<int> lps(n, 0);
        
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Fallback to the previous best match
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // The last element of the LPS array gives the length of the longest happy prefix
        int longest_len = lps[n - 1];
        
        return s.substr(0, longest_len);
    }
};
