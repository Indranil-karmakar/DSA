class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, grid, vis);
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};