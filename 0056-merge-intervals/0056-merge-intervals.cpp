#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            // If answer is empty or no overlap
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                // Overlapping intervals, merge them
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};