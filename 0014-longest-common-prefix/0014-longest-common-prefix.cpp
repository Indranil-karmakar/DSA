class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.size() == 1) return str[0];
        sort(str.begin(), str.end());
        string ans = "";
        string s1 = str[0];
        string s2 = str[str.size() - 1];
        int x = 0;
        int y = 0;
        while(x < s1.size() && y < s2.size()) {
            if(s1[x] == s2[y]) {
                ans += s1[x];
                x++;
                y++;
            }
            else {
                break;
            }
        }
        return ans;
    }
};