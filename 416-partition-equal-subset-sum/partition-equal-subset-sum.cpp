class Solution {
public:
    int dp[201][10001];
    bool solve(int curr, int i, int total_sum, vector<int>& nums) {
        if (i == nums.size()) {
            if (curr == total_sum / 2) {
                return true;
            }
            return false;
        }
        if (curr == total_sum / 2) {
            return true;
        } else if (curr > total_sum / 2) {
            return false;
        }
        if (dp[i][curr] != -1) {
            return dp[i][curr];
        }

        return dp[i][curr] = solve(curr + nums[i], i + 1, total_sum, nums) ||
                             solve(curr, i + 1, total_sum, nums);
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % 2 != 0) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, total_sum, nums);
    }
};