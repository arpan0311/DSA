class Solution {
public:
    int dp[30001][2];
    int solve(vector<int>& prices, bool canbuy, int i) {
        if (i >= prices.size()) {
            return 0;
        }
        // case 1 can take
        if (dp[i][canbuy] != -1) {
            return dp[i][canbuy];
        }
        int take = 0, nottake = 0;
        if (canbuy) {
            take = -prices[i] + solve(prices, false, i + 1);
            nottake = solve(prices, canbuy, i + 1);

        } else {
            take = prices[i] + solve(prices, true, i + 1);
            nottake = solve(prices, canbuy, i + 1);
        }

        return dp[i][canbuy] = max(take, nottake);
    }
    int maxProfit(vector<int>& prices) {
        int curr = 0, i = 0;
        bool cantake = true;
        int profit = 0;
        memset(dp, -1, sizeof(dp));
        return solve(prices, cantake, i);
    }
};