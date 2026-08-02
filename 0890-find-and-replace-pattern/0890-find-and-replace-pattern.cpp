class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            unordered_map<char, char> mp1;
            unordered_map<char, char> mp2;
            bool valid = true;
        
          for(int i=0; i<pattern.length(); i++) {
                if(mp1.find(pattern[i]) != mp1.end() && mp1[pattern[i]] != word[i]) {
                    valid = false;
                    break;
                }
                if(mp2.find(word[i]) != mp2.end() && mp2[word[i]] != pattern[i]) {
                    valid = false;
                    break;
                }
                mp1[pattern[i]] = word[i];
                mp2[word[i]] = pattern[i];
            }
            if(valid) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};