class Solution {
public:
    int dp[1001][2001];
    int solve(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) {
            return sum == target;
        }
        if (dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];

        int plus  = solve(nums, i + 1, sum + nums[i], target);
        int minus = solve(nums, i + 1, sum - nums[i], target);

        return dp[i][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, target);
    }
};
