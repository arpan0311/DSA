class Solution {
public:
int dp[15][2][2][1024];
int solve(string& s, int idx, bool lz, bool tight, int bits) {
        if (idx == s.length()) {
            if (bits != 0) {
                return 1;
            }
            // only zeros
            return 0;
        }
        if (dp[idx][lz][tight][bits] != -1) {
            return dp[idx][lz][tight][bits];
        }
        int lb = 0, ub = 9;
        if (tight) {
            ub = s[idx] - '0';
        }
        int total = 0;
        for (int i = lb; i <= ub; i++) {
            // already used element...
            if (lz && i == 0) {
                total +=
                    solve(s, idx + 1, (lz && i == 0), (tight && i == ub), bits);
            } else {
                if (bits & (1 << i)) {
                    continue;
                }

                total += solve(s, idx + 1, (lz && i == 0), (tight && i == ub),
                               bits | (1 << i));
            }
        }
        return dp[idx][lz][tight][bits] = total;
    }
    int numDupDigitsAtMostN(int n) {
         string s = to_string(n);
        int ind = 0;
        bool lz = true, tight = true;
        int bits = 0;
        memset(dp, -1, sizeof(dp));
        return n-solve(s, ind, lz, tight, bits);
    }
};