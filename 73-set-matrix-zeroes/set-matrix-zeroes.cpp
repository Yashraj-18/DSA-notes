        // int row[n] = {0};
        // int col[m] = {0};
        // error: variable-sized object may not be initialized
        //           int row[n] = {0};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows
        int m = matrix[0].size();     // Number of columns

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // First pass to find all zeroes and mark corresponding row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass to set matrix elements to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
