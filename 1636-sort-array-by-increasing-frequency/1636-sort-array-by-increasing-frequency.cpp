class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> bucket(n+1);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            mp[num]++;
        }
        for(auto it : mp) {
            int el = it.first;
            int freq = it.second;
            bucket[freq].push_back(el);
        }
        for (int freq = 1; freq <= n; freq++) {

            // Same frequency -> larger value first
            sort(bucket[freq].rbegin(), bucket[freq].rend());

            for (int el : bucket[freq]) {
                for (int i = 0; i < freq; i++) {
                    ans.push_back(el);
                }
            }
        }

        return ans;

    }
};