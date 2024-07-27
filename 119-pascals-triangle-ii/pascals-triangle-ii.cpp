class Solution {
public:
    // Function to calculate the binomial coefficient nCr
    long long nCr(int n, int r) {
        long long res = 1;

        // Calculate nCr
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    // Function to get the rowIndex-th row of Pascal's Triangle
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);

        // Fill in the row
        for (int col = 0; col <= rowIndex; col++) {
            row[col] = nCr(rowIndex, col);
        }

        return row;
    }
};
