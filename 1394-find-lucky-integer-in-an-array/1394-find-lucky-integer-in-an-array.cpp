class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int ans = -1;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        for(auto it : mp) {
            int el = it.first;
            int freq = it.second;
            if(el == freq) {
                ans = max(ans, el);
            }
            
        }
        return ans;
    }
};