class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '(') {
                cur++;
                res = max(res, cur);
            }
            if(ch == ')') {
                cur--;
            }
        }
        return res;
    }
};