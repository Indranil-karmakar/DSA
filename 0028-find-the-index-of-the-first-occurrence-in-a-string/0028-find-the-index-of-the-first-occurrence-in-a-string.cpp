class Solution {
public:

    void buildLPS(vector<int>& lps, string s) {
        int pref = 0, suff = 1;

        while(suff < s.size()) {
            if(s[pref] == s[suff]) {
                lps[suff] = pref + 1;
                pref++;
                suff++;
            }
            else {
                if(pref == 0) {
                    lps[suff] = 0;
                    suff++;
                }
                else {
                    pref = lps[pref - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {

        if(needle.size() == 0) return 0;

        vector<int> lps(needle.size(), 0);

        buildLPS(lps, needle);

        int first = 0, second = 0;

        while(first < haystack.size()) {

            if(haystack[first] == needle[second]) {
                first++;
                second++;
            }

            if(second == needle.size()) {
                return first - second;
            }

            else if(first < haystack.size() && haystack[first] != needle[second]) {

                if(second != 0) {
                    second = lps[second - 1];
                }
                else {
                    first++;
                }
            }
        }

        return -1;
    }
};