class Solution {
public:
    int countSubsequences(string &s, int n) {

        const int MOD = 1e9 + 7;

        vector<long long> dp(n, 0);

        for (char c : s) {

            int digit = c - '0';

            vector<long long> ndp = dp;

            // Single digit subsequence
            ndp[digit % n]++;

            // Extend previous subsequences
            for (int rem = 0; rem < n; rem++) {

                int newRem = (rem * 10 + digit) % n;

                ndp[newRem] += dp[rem];

                if (ndp[newRem] >= MOD)
                    ndp[newRem] -= MOD;
            }

            dp = ndp;
        }

        return dp[0];
    }
};