class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid){

        int rows = grid.size();
        int cols = grid[0].size();

        //boundry condition
        if(i < 0 || j < 0 || i >= rows || j >= cols || vis[i][j] || grid[i][j] == 1){
            return;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vis[i][j] = true;

        for(int k = 0; k < 4; k++){
            int newRow = i + dr[k];
            int newCol = j + dc[k];

            dfs(newRow, newCol, vis, grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // border island checking
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if((i == 0 ||  j == 0 || i == rows - 1 || j == cols - 1) && grid[i][j] == 0){
                    dfs(i, j, vis, grid);
                }
            }
        }

        // count remaining island
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]== 0 && !vis[i][j]){
                    dfs(i, j, vis, grid);
                    count++;
                }
            }
        }


        return count;
    }
};