class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
          [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int count = 0;
        int lastEndTime = INT_MIN;
        for(auto interval: intervals) {
            int startTime = interval[0];
            int endTime  = interval[1];
            if(startTime >= lastEndTime) {
                count++;
                lastEndTime = endTime;
            }
        }
        return n - count;
    } 
}; 