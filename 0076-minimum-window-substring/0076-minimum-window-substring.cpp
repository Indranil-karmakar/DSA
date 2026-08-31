class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        
        for(char c : t) {
            mp[c]++;
        }
        
        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;
        
        while(right < s.size()) {
            if(mp[s[right]] > 0) {
                count--;
            }
            mp[s[right]]--;
            
            while(count == 0) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                
                mp[s[left]]++;
                if(mp[s[left]] > 0) {
                    count++;
                }
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};