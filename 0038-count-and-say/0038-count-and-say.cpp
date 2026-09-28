class Solution {
public:
    string countAndSay(int n) {
        // Base case for n = 1
        string current = "1";
        
        // Iteratively build the sequence from 2 to n
        for (int i = 2; i <= n; ++i) {
            string next_seq = "";
            int len = current.length();
            
            // Pointer to track the characters in the current string
            int j = 0;
            while (j < len) {
                char ch = current[j];
                int count = 0;
                
                // Count consecutive identical characters
                while (j < len && current[j] == ch) {
                    count++;
                    j++;
                }
                
                // Append the count followed by the character itself
                next_seq += to_string(count) + ch;
            }
            
            // Move to the next sequence
            current = next_seq;
        }
        
        return current;
    }
};
