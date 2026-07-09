class Solution {
public:
    int dp[35][3][2];
    string s;

    int solve(int idx, int bits, int prev, bool tight) {
        if (idx == bits) {
            return 1;
        }

        if (dp[idx][prev][tight] != -1) {
            return dp[idx][prev][tight];
        }

        int total = 0;

        int limit = tight ? (s[idx] - '0') : 1;

        for (int i = 0; i <= limit; i++) {

            // Don't allow consecutive 1's
            if (prev == 1 && i == 1)
                continue;

            total += solve(idx + 1,
                           bits,
                           i,
                           tight && (i == limit));
        }

        return dp[idx][prev][tight] = total;
    }

    int findIntegers(int n) {

        s = "";

        if (n == 0)
            return 1;

        while (n > 0) {
            s += char('0' + (n % 2));
            n /= 2;
        }

        reverse(s.begin(), s.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, s.size(), 2, true);
    }
};