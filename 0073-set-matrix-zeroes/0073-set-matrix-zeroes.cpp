class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // number of rows
        int m = matrix[0].size(); // number of columns

        vector<int> row(n, 0); // to mark rows that should be set to zero
        vector<int> col(m, 0); // to mark columns that should be set to zero

        // First pass: mark the rows and columns that need to be zeroed
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set the marked rows and columns to zero
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};