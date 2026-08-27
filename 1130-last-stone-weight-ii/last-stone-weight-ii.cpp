class Solution {
public:
    vector<vector<int>> dp;
    int total = 0;
    int solve(vector<int>& nums, int i, int curr) {
        if (i == nums.size()) {
            // abs send kiya kyoki negative answer nhi ho satka
            return abs(curr);
        }
        if (dp[i][curr + total] != -1) {
            return dp[i][curr + total];
        }

        int take = solve(nums, i + 1, curr + nums[i]);
        int not_take = solve(nums, i + 1, curr - nums[i]);
        dp[i][curr + total] = max(0,min(take, not_take));
        return dp[i][curr + total];
    }
    int lastStoneWeightII(vector<int>& nums) {
        int curr = 0;
        int i = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        dp.assign(nums.size(), vector<int>(2 * total, -1));
       return solve(nums, i, curr);
        // return (maxi == INT_MAX ? 0 : maxi);
    }
};
// 2*total becouse sum can be negative as welll