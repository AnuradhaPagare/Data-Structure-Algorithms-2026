class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long current = 1;
        for (int j = 1; j < rowIndex; ++j) {
            current = current * (rowIndex - j + 1) / j;
            row[j] = current;
        }
        return row;
    }
};
