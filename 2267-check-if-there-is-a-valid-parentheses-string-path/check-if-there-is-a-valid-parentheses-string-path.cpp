class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 == 1)
            return false;

        // First must be '(' and last must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // t[i][j][open] = can we reach destination
        // from (i,j) with current balance = open?
        int t[101][101][201] = {};

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // Check ALL possible balances
                for (int open = 0; open <= m + n; open++) {

                    // Destination
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][open] = (open == 0);
                        continue;
                    }

                    // Move Down
                    if (i < m - 1) {
                        int newcount =
                            (grid[i + 1][j] == '(')
                            ? open + 1
                            : open - 1;

                        if (newcount >= 0 &&
                            t[i + 1][j][newcount]) {
                            t[i][j][open] = true;
                        }
                    }

                    // Move Right
                    if (j < n - 1) {
                        int newcount =
                            (grid[i][j + 1] == '(')
                            ? open + 1
                            : open - 1;

                        if (newcount >= 0 &&
                            t[i][j + 1][newcount]) {
                            t[i][j][open] = true;
                        }
                    }
                }
            }
        }

        // Starting '(' gives balance = 1
        return t[0][0][1];
    }
};