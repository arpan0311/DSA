class Solution {
public:
    // int dp[301][5001];
    // int solve(vector<int>& coins, int amount, int i) {
    //     if (i >= coins.size()) {
    //         if (amount == 0) {
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if (dp[i][amount] != -1) {
    //         return dp[i][amount];
    //     }
    //     int take = 0;
    //     if (coins[i] <= amount) {
    //         take = solve(coins, amount - coins[i], i);
    //     }
    //     int notTake = solve(coins, amount, i + 1);
    //     return dp[i][amount] = take + notTake;
    // }
    int change(int amount, vector<int>& coins) {
        // sort(coins.begin(),coins.end());
        // memset(dp,-1,sizeof(dp));
        // return solve(coins,amount,0);
        int dp[301][5001];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= amount; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= coins.size(); i++) {
            dp[i][0] = 1;
        }
        int n = coins.size();
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                long long take = 0;
                if (coins[i - 1] <= j) {
                    // in this case I used n-1th index so I write here i not i-1
                    take = dp[i][j - coins[i - 1]];
                }
                long long nottake = dp[i - 1][j];
                dp[i][j] = take + nottake;
            }
        }
        return dp[n][amount];
    }
};