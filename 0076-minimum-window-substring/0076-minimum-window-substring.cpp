class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> targetCounts;
        for (char c : t) {
            targetCounts[c]++;
        }

        unordered_map<char, int> windowCounts;
        int left = 0, right = 0;
        int required = targetCounts.size();
        int formed = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;

            if (targetCounts.count(c) && windowCounts[c] == targetCounts[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                windowCounts[c]--;
                if (targetCounts.count(c) && windowCounts[c] < targetCounts[c]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
