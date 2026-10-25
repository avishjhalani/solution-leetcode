class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];

                    if (x < 0 || y < 0 || x >= n || y >= m)
                        continue;

                    if (maze[x][y] == '+')
                        continue;

                    if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
                        return steps + 1;

                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }

            steps++;
        }

        return -1;
    }
};