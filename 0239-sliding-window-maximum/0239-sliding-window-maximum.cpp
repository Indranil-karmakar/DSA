class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        // first window
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // remaining windows
        for(int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);

            // remove out-of-window elements
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // maintain decreasing order
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // last window
        res.push_back(nums[dq.front()]);
        return res;
    }
};