class Solution {
public:

    void dfs(int i,  int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int rows, int cols){

        if(i < 0|| j < 0 || i >= rows || j >= cols || vis[i][j] || grid[i][j] != '1'){
            return;
        }
        vis[i][j] = true;

        dfs(i - 1, j, vis, grid, rows, cols);
        dfs(i + 1, j, vis, grid, rows, cols);
        dfs(i, j - 1, vis, grid, rows, cols);
        dfs(i, j + 1, vis, grid, rows, cols);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, vis, grid, rows, cols);
                    count++;
                }
            }
        }
        return count;
    }
};