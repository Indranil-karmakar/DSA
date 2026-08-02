class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            char k = s[i];
            if(k == ' ') {
                word.push_back(temp);
                temp = "";
            }
            else{
                temp += k;
            }
            
        }
        word.push_back(temp);
        if(pattern.size() != word.size()) return false;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for(int i=0; i<pattern.size(); i++) {
            if(mp1.find(pattern[i]) != mp1.end() && mp1[pattern[i]] != word[i]){
                return false;
            }
            if(mp2.find(word[i]) != mp2.end() && mp2[word[i]] != pattern[i]) {
                return false;
            }
            mp1[pattern[i]] = word[i];
            mp2[word[i]] = pattern[i];
        }
        return true;

    }
};