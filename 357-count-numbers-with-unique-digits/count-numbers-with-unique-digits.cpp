class Solution {
public:
    int dp[10][2][2][1024];
    int solve(string& s, int idx, bool tight, bool lz, int mask) {
        if (idx == s.length()) {
            return 1;
        }
        if(dp[idx][lz][tight][mask]!=-1){
            return dp[idx][lz][tight][mask];
        }
        int lb = 0, ub = tight ? (s[idx] - '0') : 9;
        int ans = 0;
        for (int i = 0; i <= ub; i++) {
            // used
            if ((mask >> i) & 1) {
                continue;
            } else {
                // abhi tk use nhi hua
                if (lz && i == 0) {
                    ans += solve(s, idx + 1, (tight && i == s[idx] - '0'),
                                 true, mask);
                } else {
                    ans += solve(s, idx + 1, (tight && i == s[idx] - '0'),
                                 (lz && i == 0), mask | (1 << i));
                }
            }
        }
        return dp[idx][lz][tight][mask]=ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int bits = 0, idx = 0;
        bool tight = true, lz = true;
        int num = pow(10, n)-1;
        cout<<num<<endl;
        string s = to_string(num);
        memset(dp,-1,sizeof(dp));
        return solve(s, idx, tight, lz, bits);
    }
};