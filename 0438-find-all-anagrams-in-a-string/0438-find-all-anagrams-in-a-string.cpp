class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> need(26, 0), window(26, 0);
        if(s.size() < p.size()) return ans;
        for(int i=0; i<p.size(); i++) {
            char ch = p[i];
            need[ch -'a']++;

        }
        int k = p.size();
        for(int i=0; i<k; i++) {
            window[s[i] -'a']++;
        }
        if(window == need) {
            ans.push_back(0);
        }
        for(int i=k; i<s.size(); i++) {
            window[s[i-k] - 'a']--;
            window[s[i] - 'a']++;
            if(window == need) {
                ans.push_back(i-k+1);
            }
        }
        return ans;

    }
};