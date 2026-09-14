class Solution {
private:
    void dfs(vector<vector<int>> &image, int r, int c, int originalcolor, int newcolor) {
        int n = image.size();
        int m = image[0].size();
        image[r][c] = newcolor;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == originalcolor) {
                dfs(image, nr, nc, originalcolor, newcolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor = image[sr][sc];
        if(originalcolor == color) return image;
        dfs(image, sr, sc, originalcolor, color);
        return image;
    }
};