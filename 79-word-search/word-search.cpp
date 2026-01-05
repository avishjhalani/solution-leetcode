class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    bool solve(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        if (idx == word.size()) return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;

        if (board[row][col] != word[idx])
            return false;

        char temp = board[row][col];
        board[row][col] = '$';

        for (auto& d : dir) {
            if (solve(board, word, row + d[0], col + d[1], idx + 1))
                return true;
        }

        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
