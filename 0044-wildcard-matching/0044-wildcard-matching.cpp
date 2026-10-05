class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int matchIdx = 0, starIdx = -1;            
        
        while (sIdx < s.length()) {
            // 1. If characters match or pattern has '?', move both pointers
            if (pIdx < p.length() && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // 2. If a star '*' is found, record its position and the current string match index
            else if (pIdx < p.length() && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++; // Advance pattern pointer to check characters after '*'
            }
            // 3. If there's a mismatch but a previous '*' was found, backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1; // Reset pattern pointer to right after the star
                matchIdx++;         // Consume one character from string via star
                sIdx = matchIdx;    // Reset string pointer to the next match attempt
            }
            // 4. Mismatch and no previous '*' to rescue
            else {
                return false;
            }
        }
        
        // 5. Check for remaining trailing '*' characters in the pattern
        while (pIdx < p.length() && p[pIdx] == '*') {
            pIdx++;
        }
        
        // If the entire pattern is consumed, it's a match
        return pIdx == p.length();
    }
};
