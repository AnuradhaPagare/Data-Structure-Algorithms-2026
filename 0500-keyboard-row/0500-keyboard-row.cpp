class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> charToRow(26, 0);
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        for (char c : row1) charToRow[c - 'a'] = 1;
        for (char c : row2) charToRow[c - 'a'] = 2;
        for (char c : row3) charToRow[c - 'a'] = 3;
        
        vector<string> result;
        
        for (const string& word : words) {
            int targetRow = charToRow[tolower(word[0]) - 'a'];
            bool isValid = true;
            
            for (char c : word) {
                if (charToRow[tolower(c) - 'a'] != targetRow) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
