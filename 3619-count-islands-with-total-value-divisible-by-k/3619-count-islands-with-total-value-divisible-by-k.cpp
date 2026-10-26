class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 0)
                    continue;

                long long sum = 0;
                queue<pair<int, int>> q;

                q.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int newRow = x + dx[d];
                        int newCol = y + dy[d];

                        if (newRow >= 0 && newRow < rows &&
                            newCol >= 0 && newCol < cols &&
                            grid[newRow][newCol] > 0) {

                            sum += grid[newRow][newCol];

                            q.push({newRow, newCol});
                            grid[newRow][newCol] = 0;
                        }
                    }
                }

                if (sum % k == 0)
                    count++;
            }
        }

        return count;
    }
};