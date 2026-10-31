class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(rows < 0 || cols < 0){
            return 0;
        }

        int count = 0;
        int MOD = 1e9 + 7;

        vector<vector<long long>>right(rows, vector<long long>(cols, 0));
        vector<vector<long long>>down(rows, vector<long long> (cols, 0));

        right[0][0] = 1;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j< cols; j++){

                //number of ways
                long long ways = (right[i][j] + down[i][j]) % MOD; 


                //mirror cell
                if(grid[i][j] == 1){
                    if(i + 1 < rows){
                        // down value increase
                        down[i + 1][j] = (down[i + 1][j] + right[i][j]) % MOD;
                    }

                    if(j + 1 < cols){
                        //right value increase
                        right[i][j + 1] = (right[i][j + 1] + down[i][j]) % MOD;
                    }
                }else{
                    //move to right
                    if(j + 1 < cols){
                        right[i][j + 1] = (right[i][j + 1] + ways) % MOD;
                    }

                    //move to down
                    if(i + 1 < rows){
                        down[i + 1][j] = (down[i + 1][j] + ways) % MOD;
                    }
                    
                }
            }
        }
        return (right[rows - 1][cols - 1] + down[rows - 1][cols - 1]) % MOD;
    }
};