class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int x, int y, int og, int color) {
        if (x < 0 || x >= image.size()) return;
        if (y < 0 || y >= image[0].size()) return;
        if (image[x][y] != og) return;
        if (image[x][y] == color) return;

        image[x][y] = color;
        dfs(image, x, y + 1, og, color);
        dfs(image, x, y - 1, og, color);
        dfs(image, x - 1, y, og, color);
        dfs(image, x + 1, y, og, color);
    }
};