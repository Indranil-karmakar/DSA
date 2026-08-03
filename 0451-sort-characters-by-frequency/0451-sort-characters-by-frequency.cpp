class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans = "";
        unordered_map<char, int> mp;
        vector<string> bucket(n+1);
        for(int i=0; i<n; i++) {
            char ch = s[i];
            mp[ch]++;
        }
        for(auto it : mp) {
            char ch = it.first;
            int freq = it.second;
            bucket[freq] += ch;
        }
        for(int freq=n; freq >= 1; freq--) {
            for(char ch : bucket[freq]) {
                ans += string(freq, ch);
            }
        }
        return ans;
    }
};