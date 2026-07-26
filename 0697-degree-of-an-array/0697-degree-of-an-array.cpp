class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, int> firstIndex;
        unordered_map<int, int> lastIndex;

        // Store frequency, first index and last index
        for (int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;

            if (firstIndex.find(nums[i]) == firstIndex.end()) {
                firstIndex[nums[i]] = i;
            }

            lastIndex[nums[i]] = i;
        }

        // Find the degree of the array
        int degree = 0;
        for (auto it : freq) {
            degree = max(degree, it.second);
        }

        // Find the minimum length subarray
        int ans = nums.size();

        for (auto it : freq) {

            int num = it.first;

            if (it.second == degree) {
                int length = lastIndex[num] - firstIndex[num] + 1;
                ans = min(ans, length);
            }
        }

        return ans;
    }
};