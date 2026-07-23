class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int n, int bits, int m) {

        if (n <= 0) {
            return false;
        }

        if (dp.count(bits))
            return dp[bits];

        // try all possible ways
        for (int i = 1; i <= m; i++) {

            // number i is not used
            if (!(bits & (1 << i))) {

                // I can win immediately
                if (i >= n)
                    return dp[bits] = true;

                if (!solve(n - i, bits | (1 << i), m))
                    return dp[bits] = true;
            }
        }

        return dp[bits] = false;
    }

    bool canIWin(int n, int m) {
        int bits = 0;
        if (n >= m)
            return true;
        if (n * (n + 1) / 2 < m)
            return false;
        return solve(m, bits, n);
    }
};