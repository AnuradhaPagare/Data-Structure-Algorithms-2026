class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int n = s.length();
        int num_words = words.size();
        int word_len = words[0].length();
        int total_len = num_words * word_len;
        
        if (n < total_len) return result;
        
        // Count frequency of each word in the input list
        unordered_map<string, int> word_counts;
        for (const string& word : words) {
            word_counts[word]++;
        }
        
        // Run the sliding window word_len times for all possible offsets
        for (int i = 0; i < word_len; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> current_counts;
            int words_used = 0;
            
            // Move the right edge of the window
            while (right + word_len <= n) {
                string word = s.substr(right, word_len);
                right += word_len;
                
                // Case 1: The word is valid
                if (word_counts.count(word)) {
                    current_counts[word]++;
                    words_used++;
                    
                    // If we exceed the maximum allowed frequency, shrink window from the left
                    while (current_counts[word] > word_counts[word]) {
                        string left_word = s.substr(left, word_len);
                        current_counts[left_word]--;
                        words_used--;
                        left += word_len;
                    }
                    
                    // If all words are matched exactly
                    if (words_used == num_words) {
                        result.push_back(left);
                    }
                } 
                // Case 2: The word is invalid, reset the window
                else {
                    current_counts.clear();
                    words_used = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};