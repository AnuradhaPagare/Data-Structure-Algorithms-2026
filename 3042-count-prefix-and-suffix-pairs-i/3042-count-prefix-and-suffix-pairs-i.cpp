class Solution {
private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        
        // If str1 is longer than str2, it can't be a prefix or suffix
        if (n1 > n2) return false;
        
        // Check if str1 matches the prefix of str2
        bool isPrefix = (str2.compare(0, n1, str1) == 0);
        
        // Check if str1 matches the suffix of str2
        bool isSuffix = (str2.compare(n2 - n1, n1, str1) == 0);
        
        return isPrefix && isSuffix;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        // Iterate through all pairs (i, j) where i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
