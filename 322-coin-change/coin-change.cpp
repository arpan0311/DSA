class Solution {
public:
    long long dp[13][10001];

    long long solve(vector<int>& nums, long long sum, int m, long long amount) {

        if (sum > amount) {
            return LLONG_MAX;
        }

        if (sum == amount) {
            return 0;
        }

        if (dp[m][sum] != -1) {
            return dp[m][sum];
        }

        long long answer = LLONG_MAX;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] + sum <= amount) {

                long long get_val =
                    solve(nums, sum + nums[i], i + 1, amount);

                if (get_val != LLONG_MAX) {
                    answer = min(answer, 1 + get_val);
                }
            }
        }

        return dp[m][sum] = answer;
    }

    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(), coins.end());

        memset(dp, -1, sizeof(dp));

        long long answer = solve(coins, 0, 0, amount);

        return (answer == LLONG_MAX ? -1 : answer);
    }
};