class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes
        if (x < 0) return false;

        // Numbers ending in 0 cannot be palindrome
        // except 0 itself
        if (x % 10 == 0 && x != 0) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Even number of digits
        if (x == reversedHalf)
            return true;

        // Odd number of digits: ignore middle digit
        return x == reversedHalf / 10;
    }
};