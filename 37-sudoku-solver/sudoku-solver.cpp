class Solution {
public:
    int rowMask[9] = {};
    int colMask[9] = {};
    int boxMask[9] = {};

    bool backtrack(vector<vector<char>>& board) {
        int emptyRow = -1;
        int emptyCol = -1;

        // Find an empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    emptyRow = row;
                    emptyCol = col;
                    break;
                }
            }

            if (emptyRow != -1)
                break;
        }

        // No empty cells remain
        if (emptyRow == -1)
            return true;

        int box = (emptyRow / 3) * 3 + (emptyCol / 3);

        // Digits 1 through 9
        for (int digit = 1; digit <= 9; digit++) {
            int bit = 1 << (digit - 1);

            // Digit already used in row, column, or box
            if ((rowMask[emptyRow] & bit) ||
                (colMask[emptyCol] & bit) ||
                (boxMask[box] & bit)) {
                continue;
            }

            // Place digit
            board[emptyRow][emptyCol] = char('0' + digit);
            rowMask[emptyRow] |= bit;
            colMask[emptyCol] |= bit;
            boxMask[box] |= bit;

            if (backtrack(board))
                return true;

            // Undo placement
            board[emptyRow][emptyCol] = '.';
            rowMask[emptyRow] ^= bit;
            colMask[emptyCol] ^= bit;
            boxMask[box] ^= bit;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // Initialize masks using the already-filled cells
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;

                int digit = board[row][col] - '1';
                int bit = 1 << digit;
                int box = (row / 3) * 3 + (col / 3);

                rowMask[row] |= bit;
                colMask[col] |= bit;
                boxMask[box] |= bit;
            }
        }

        backtrack(board);
    }
};