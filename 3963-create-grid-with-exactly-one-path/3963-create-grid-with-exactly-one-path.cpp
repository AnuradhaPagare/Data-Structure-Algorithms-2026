class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m, string(n, '#'));

        int i = 0;
        int j = 0;

        grid[i][j] = '.';

        while(i < m - 1 || j < n - 1){
            if(i < m - 1){
                i++;
            }else{
                j++;
            }
            grid[i][j] = '.';
        }
        return grid;
    }
};