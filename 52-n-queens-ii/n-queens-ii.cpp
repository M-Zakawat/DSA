class Solution {
public:
    int count = 0;

    void backtrack(
        int row,
        int n,
        vector<bool>& cols,
        vector<bool>& diag1,
        vector<bool>& diag2
    ) {
        // All queens are successfully placed
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {

            // Check column and diagonals
            if (cols[col] ||
                diag1[row - col + n - 1] ||
                diag2[row + col]) {
                continue;
            }

            // Place queen
            cols[col] = true;
            diag1[row - col + n - 1] = true;
            diag2[row + col] = true;

            // Move to next row
            backtrack(row + 1, n, cols, diag1, diag2);

            // Backtrack
            cols[col] = false;
            diag1[row - col + n - 1] = false;
            diag2[row + col] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false);

        // There are 2n - 1 possible diagonals
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, cols, diag1, diag2);

        return count;
    }
};