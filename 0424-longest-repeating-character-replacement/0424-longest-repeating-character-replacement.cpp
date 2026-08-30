class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        unordered_map<int, int> mp;
        while(r < n) {
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            int len = r-l+1;
            if(len - maxfreq > k) {
                mp[s[l]]--;
                
                l++;

            }
            if(len - maxfreq <= k) {
                maxlen = max(maxlen, len);

            }
            r++;
        }
        return maxlen;
        
    }
};