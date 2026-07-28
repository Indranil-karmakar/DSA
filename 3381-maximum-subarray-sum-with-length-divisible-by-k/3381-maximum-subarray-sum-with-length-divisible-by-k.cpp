class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;

        long long prefixSum = 0;
        long long ans = LLONG_MIN;

        // prefix sum before array starts
        mp[0] = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int rem = (i + 1) % k;

            // If same remainder exists,
            // length of subarray is divisible by k
            if (mp.find(rem) != mp.end()) {
                ans = max(ans, prefixSum - mp[rem]);
            }

            // Store minimum prefix sum for this remainder
            if (mp.find(rem) == mp.end()) {
                mp[rem] = prefixSum;
            }
            else {
                mp[rem] = min(mp[rem], prefixSum);
            }
        }

        return ans;
    }
};