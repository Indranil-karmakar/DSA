class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int len = 1; len<=n/2; len++) {
            if(n % len != 0) {
                continue;
            }
            bool ok = true;
            string pattern = s.substr(0, len);
            for(int i = len; i<n; i+=len) {
                if(s.substr(i, len) != pattern) {
                    ok = false;
                    break;

                }
            }
            if(ok) {
                return true;
            }
        }
        return false;
    }
};