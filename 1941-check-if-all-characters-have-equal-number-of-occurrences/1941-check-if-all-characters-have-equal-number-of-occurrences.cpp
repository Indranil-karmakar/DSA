class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            mp[ch]++;
        }
        int freq = mp.begin()->second;
        for(auto it : mp) {
            if(it.second != freq) {
                return false;
            }
        }
        return true;
    }
};