class Solution {
public:
    long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        // Base case
        if (exp == 0) {
            return 1;
        }

        // Recursive call
        long long half = power(base, exp / 2);

        // If exponent is even
        if (exp % 2 == 0) {
            return (half * half) % MOD;
        }

        // If exponent is odd
        return (half * half % MOD * base) % MOD;
    }

    int countGoodNumbers(long long n) {

        // Even indices: 0, 2, 4, ...
        // 5 choices: 0, 2, 4, 6, 8
        long long evenPositions = (n + 1) / 2;

        // Odd indices: 1, 3, 5, ...
        // 4 choices: 2, 3, 5, 7
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return (evenWays * oddWays) % MOD;
    }
};