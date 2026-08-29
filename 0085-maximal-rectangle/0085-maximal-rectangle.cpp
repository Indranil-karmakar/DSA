class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        stack<int> s;
        vector<int> leftS(n);
        vector<int> rightS(n);

        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && height[s.top()] >= height[i]) {
                s.pop();
            }
            rightS[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        for(int i=0; i<n; i++) {
            while(!s.empty() && height[s.top()] >= height[i]) {
                s.pop();
            }
            leftS[i] = s.empty() ? -1: s.top();
            s.push(i);
        }
        int maxarea = 0;
        for(int i=0; i<n; i++) {
            int width = rightS[i] - leftS[i] - 1;
            int area = width * height[i];
            maxarea = max(maxarea, area);
        }
        return maxarea;
    } 

    

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);

        int ans = 0;

        // Convert each row into a histogram
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1')
                    height[j]++;

                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};