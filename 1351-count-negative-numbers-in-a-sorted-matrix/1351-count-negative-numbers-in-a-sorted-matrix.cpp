class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            int firstNegative = m;   // assume no negative

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (grid[i][mid] < 0) {
                    firstNegative = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            count += (m - firstNegative);
        }

        return count;
    }
};