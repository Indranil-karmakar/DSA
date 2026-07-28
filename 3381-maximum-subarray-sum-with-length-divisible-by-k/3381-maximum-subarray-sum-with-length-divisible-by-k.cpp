class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> minPrefix(k, LLONG_MAX);

        long long prefixSum = 0;
        long long ans = LLONG_MIN;

        // prefix sum before starting
        minPrefix[0] = 0;

        for (int i = 0; i < n; i++) {

            prefixSum += nums[i];

            int rem = (i + 1) % k;

            // If we have seen this remainder before,
            // the length between them is divisible by k
            if (minPrefix[rem] != LLONG_MAX) {
                ans = max(ans, prefixSum - minPrefix[rem]);
            }

            // Store the minimum prefix sum for this remainder
            minPrefix[rem] = min(minPrefix[rem], prefixSum);
        }

        return ans;
    }
};