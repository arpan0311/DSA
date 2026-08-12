class Solution {
public:
    int dp[201][10001];
    bool solve(int curr, int total, vector<int>& nums, int i) {
        if (curr == total / 2) {
            return true;
        }

        if (i >= nums.size() || curr > total / 2) {
            return false;
        }
        if (dp[i][curr] != -1) {
            return dp[i][curr];
        }
        bool take = solve(curr + nums[i], total, nums, i + 1);
        bool not_take = solve(curr, total, nums, i + 1);
        return dp[i][curr] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, total, nums, 0);
    }
};