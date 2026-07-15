class Solution {
public:
    int  dp[10][2][2];
    int solve(int idx, bool lz, bool tight, int mask, string& s) {
        if (idx == s.length()) {
            if (lz) {
                return 0;
            }
            return 1;
        }

        if(dp[idx][lz][tight]!=-1){
            return dp[idx][lz][tight];
        }

        int lb = 0, ub = 9;
        if (tight) {
            ub = s[idx] - '0';
        }
        int ans = 0;
        for (int i = lb; i <= ub; i++) {
            if (lz && i == 0) {
                ans += solve(idx + 1, true, tight && (i == ub), mask, s);
            } else {
                if (!(1 & (mask >> i))) {
                    continue;
                }
                ans +=
                    solve(idx + 1, false, (tight && (i == ub)), mask, s);
            }
        }
        return dp[idx][lz][tight]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& nums, int n) {
        int idx = 0;
        bool lz = true, tight = true;

        int mask = 0;
        for (int i = 0; i < nums.size(); i++) {
            // set mask
            mask |= 1 << (stoi(nums[i]));
        }

        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(idx, lz, tight, mask, s);
    }
};