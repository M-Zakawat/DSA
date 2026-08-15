var solveNQueens = function(n) {
    const result = [];

    // Create empty board
    const board = Array.from({ length: n }, () => Array(n).fill('.'));

    const cols = new Set();
    const diag1 = new Set(); // row - col
    const diag2 = new Set(); // row + col

    function backtrack(row) {
        // All queens have been placed
        if (row === n) {
            result.push(
                board.map(row => row.join(''))
            );
            return;
        }

        // Try every column in current row
        for (let col = 0; col < n; col++) {

            // Check if position is under attack
            if (
                cols.has(col) ||
                diag1.has(row - col) ||
                diag2.has(row + col)
            ) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';

            cols.add(col);
            diag1.add(row - col);
            diag2.add(row + col);

            // Move to next row
            backtrack(row + 1);

            // Backtrack: remove queen
            board[row][col] = '.';

            cols.delete(col);
            diag1.delete(row - col);
            diag2.delete(row + col);
        }
    }

    backtrack(0);

    return result;
};