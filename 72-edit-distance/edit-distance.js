var minDistance = function(word1, word2) {
    let m = word1.length;
    let n = word2.length;

    let dp = Array.from(
        { length: m + 1 },
        () => Array(n + 1).fill(0)
    );

    // Convert word1 → empty string
    for (let i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    // Convert empty string → word2
    for (let j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {

            // Characters are the same
            if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }

            // Characters are different
            else {
                let insert = dp[i][j - 1];
                let deleteChar = dp[i - 1][j];
                let replace = dp[i - 1][j - 1];

                dp[i][j] = 1 + Math.min(
                    insert,
                    deleteChar,
                    replace
                );
            }
        }
    }

    return dp[m][n];
};