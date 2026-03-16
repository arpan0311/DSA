class Solution {
public:
    int dp[10][2][10];
    long long solve(string& s, int idx, bool tight, long long one) {
        if (idx == s.length()) {
            return one;
        }
        if(dp[idx][tight][one]!=-1){
            return dp[idx][tight][one];
        }
        long long lb = 0;
        long long ub;
        if (tight != 1) {
            ub = 9;
        } else {
            ub = s[idx] - '0';
        }
        long long ans = 0;
        for (int i = lb; i <= ub; i++) {
            bool new_tight = tight && (i == ub);
            if (i != 1) {
                ans += solve(s, idx + 1, new_tight, one);
            } else {
                ans += solve(s, idx + 1, new_tight, one + 1);
            }
        }

        return dp[idx][tight][one]=ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s, 0, true, 0);
    }
};