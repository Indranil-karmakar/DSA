class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> freq(3, 0);

        int l = 0;
        int count = 0;

        for (int r = 0; r < n; r++) {

            // Add current character
            freq[s[r] - 'a']++;

            // Window contains a, b and c
            while (freq[0] > 0 &&
                   freq[1] > 0 &&
                   freq[2] > 0) {

                // Remove from left
                freq[s[l] - 'a']--;
                l++;
            }

            // All substrings ending at r
            // starting from 0 to l-1 are valid
            count += l;
        }

        return count;
    }
};