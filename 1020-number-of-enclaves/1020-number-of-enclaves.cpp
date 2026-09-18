class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        // First row and last row
        for(int j = 0; j < m; j++) {

            // First row
            if(grid[0][j] == 1 && !vis[0][j]) {
                q.push({0, j});
                vis[0][j] = 1;
            }

            // Last row
            if(grid[n-1][j] == 1 && !vis[n-1][j]) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        // First column and last column
        for(int i = 0; i < n; i++) {

            // First column
            if(grid[i][0] == 1 && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = 1;
            }

            // Last column
            if(grid[i][m-1] == 1 && !vis[i][m-1]) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // BFS
        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol] &&
                   grid[nrow][ncol] == 1) {

                    vis[nrow][ncol] = 1;

                    q.push({nrow, ncol});
                }
            }
        }

        // Count unvisited land
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};