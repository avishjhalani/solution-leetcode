class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int n;

    bool check(vector<vector<int>>& disTheif, int mid) {
        if (disTheif[0][0] < mid || disTheif[n - 1][n - 1] < mid)
            return false;

        queue<pair<int, int>> que;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        que.push({0, 0});
        vis[0][0] = true;

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (const auto& dir : direction) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj] &&
                    disTheif[ni][nj] >= mid) {

                    vis[ni][nj] = true;
                    que.push({ni, nj});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> disTheif(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int cur_i = que.front().first;
                int cur_j = que.front().second;
                que.pop();
                disTheif[cur_i][cur_j] = level;
                for (vector<int> dir : direction) {
                    int new_i = cur_i + dir[0];
                    int new_j = cur_j + dir[1];

                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n ||
                        vis[new_i][new_j]) {
                        continue;
                    }
                    que.push({new_i, new_j});
                    vis[new_i][new_j] = true;
                }
            }
            level++;
        }

        int l = 0;
        int r = 2 * n;
        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(disTheif, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};