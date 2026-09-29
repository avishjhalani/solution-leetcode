class Solution {
public:
    int n, m;
    int t[101][101][201];

    bool solve(vector<vector<char>>& grid, int i, int j, int open) {

        // Process current cell
        open += (grid[i][j] == '(' ? 1 : -1);

        // Invalid prefix
        if (open < 0)
            return false;

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return open == 0;

        // Check memo
        if (t[i][j][open] != -1)
            return t[i][j][open];

        // Move down
        if (i < m - 1) {
            if (solve(grid, i + 1, j, open))
                return t[i][j][open] = true;
        }

        // Move right
        if (j < n - 1) {
            if (solve(grid, i, j + 1, open))
                return t[i][j][open] = true;
        }

        return t[i][j][open] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 == 1)
            return false;

        // First must be '(' and last must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        memset(t, -1, sizeof(t));

        return solve(grid, 0, 0, 0);
    }
};