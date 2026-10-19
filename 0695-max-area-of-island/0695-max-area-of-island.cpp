class Solution {
public:

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>& grid, int &n, int &m, int &max1){
        if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] || grid[i][j]==0){
           return;
        }
        vis[i][j] = true;
        max1++;
        
        for(int k = 0; k < 4; k++){
            int newRow = i + dr[k];
            int newCol = j + dc[k];
            dfs(newRow, newCol, vis, grid, n, m, max1);
        }
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        if(n == 0){
            return 0;
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));

    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int max1 = 0;
                    dfs(i, j, vis, grid, n, m, max1);
                    maxArea = max(maxArea, max1);
                }
            }
        }

    
        return maxArea;
    }
};