class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            mp1[ch]++;
        }
        for(int i=0; i<t.size(); i++) {
            char ch = t[i];
            mp2[ch]++;
        }
        if(mp1 == mp2) {
            return true;
        }
        return false;
    }
};