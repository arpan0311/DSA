class Solution {
public:
    int dp[101];
    int solve(string& s, int i) {
        if (i == s.length()) {
            return 1;
        }
        if (i > s.length()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // operation 1
        // use only one character

        int not_take = 0;
        // if we have two  char we will check
        if (i + 1 < s.length()) {
            string temp = s.substr(i, 2);
            int num = stoi(temp);
            if (num <= 26 && num >= 10) {
                not_take = solve(s, i + 2);
            }
        }
        int take = 0;
        if (s[i] != '0') {
            take = solve(s, i + 1);
        }

        return dp[i] = take + not_take;
    }
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') {
            return 0;
        }
        // string
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};