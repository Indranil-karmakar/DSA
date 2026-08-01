class Solution {
public:
    string reverseWords(string s) {
        // int n = s.size();
        // string ans = "";
        // int i = n - 1;

        // while (i >= 0) {

        //     // Skip spaces
        //     while (i >= 0 && s[i] == ' ')
        //         i--;

        //     if (i < 0)
        //         break;

        //     // Mark end of word
        //     int end = i;

        //     // Move to start of word
        //     while (i >= 0 && s[i] != ' ')
        //         i--;

        //     // Add space between words
        //     if (!ans.empty())
        //         ans += " ";

        //     // Append current word
        //     ans += s.substr(i + 1, end - i);
        // }

        // return ans;
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++) {
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0) {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};