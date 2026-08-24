class Solution {
public:
    bool palindrome(string s) {
        int right = s.length()-1;
        int left = 0;
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string word: words) {
            if(palindrome(word)) {
                return word;
            }
        }
        return "";
    }
};