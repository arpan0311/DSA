class Solution {
public:
    long long dp[100001];
    long long solve(vector<vector<int>>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long long take = 0, not_take = 0;

        take = nums[i][0] + solve(nums, i + 1 + nums[i][1]);
        not_take = solve(nums, i + 1);
        return dp[i] = max(take, not_take);
    }
    long long mostPoints(vector<vector<int>>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};