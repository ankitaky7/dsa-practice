class Solution {
    // #define ed endl;
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int &cnt, int row, int col){
        vis[row][col] = 1;
        // cnt = cnt + 1;
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for(int i = 0;i < 4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                // cout << cnt ;
                dfs(grid, vis, cnt, nrow, ncol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, vis, cnt, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};