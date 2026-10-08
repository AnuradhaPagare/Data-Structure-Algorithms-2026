class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        unordered_map<char, int> boardFreq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                boardFreq[board[i][j]]++;
            }
        }
        
        unordered_map<char, int> wordFreq;
        for (char c : word) {
            wordFreq[c]++;
            if (wordFreq[c] > boardFreq[c]) return false; 
        }
        
        if (boardFreq[word.back()] < boardFreq[word.front()]) {
            reverse(word.begin(), word.end());
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.length()) return true;
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        char temp = board[r][c];
        board[r][c] = '#';
        
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);
        
        board[r][c] = temp;
        
        return found;
    }
};
