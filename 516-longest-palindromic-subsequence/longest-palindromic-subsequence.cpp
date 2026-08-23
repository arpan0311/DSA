class Solution {
public:
    int dp[1001][1001];
    int solve(string& s, int i, int j) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (i == j) {
            return 1;
        }
        int take = 0, skip_i = 0, skip_j = 0;
        if (s[i] == s[j]) {
            take = 2 + solve(s, i + 1, j - 1);
        } else {
            skip_i = solve(s, i + 1, j);
            skip_j = solve(s, i, j - 1);
        }

        return dp[i][j]=max(take, max(skip_i, skip_j));
    }
    int longestPalindromeSubseq(string s) {
        int i = 0, j = s.length() - 1;
        memset(dp,-1,sizeof(dp));
        return solve(s, i, j);
    }
};