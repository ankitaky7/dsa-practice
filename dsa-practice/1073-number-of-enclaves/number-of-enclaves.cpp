class Solution {
private: 
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(grid, vis, nrow, ncol);
            }
        }
}

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        // to traverse along first and last column
        for(int j = 0;j < m; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(grid, vis, 0, j);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(grid, vis, n - 1, j);
            }
        }

        for(int i = 0;i < n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(grid, vis, i, 0);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(grid, vis, i, m-1);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};