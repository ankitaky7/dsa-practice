class Solution {
private:
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& board, int n,
             int m, int row, int col) {
        vis[row][col] = 1;

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(vis, board, n, m, nrow, ncol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // for traversing first and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(vis, board, n, m, 0, j);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(vis, board, n, m, n - 1, j);
            }
        }

        // for traversing first and last col
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(vis, board, n, m, i, 0);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(vis, board, n, m, i, m - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};