class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        vector<int> prefsum(n, 0);
        prefsum[0] = nums[0];
        int count = 0;
        for(int i=1; i<n; i++) {
            prefsum[i] = prefsum[i-1] + nums[i];
        }
        for(int j=0; j<n; j++) {
            int remainder = prefsum[j] % k;
            remainder = (remainder + k) % k;
            if(mp.find(remainder) != mp.end()) {
                count += mp[remainder];
            }
            mp[remainder]++;
        }
        return count;
    }
};