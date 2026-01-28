class Solution {
public:
    int dp[2501][2502];
    int solve(vector<int>& nums, int prev, int curr) {
        if (nums.size() == curr) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }
        int take = 0;
        int nottake = solve(nums, prev, curr + 1);
        if (prev == -1 || prev !=-1 && nums[curr] > nums[prev]) {
            take = 1 + solve(nums, curr, curr + 1);
        }

        dp[curr][prev + 1] = max(take, nottake);
        return dp[curr][prev + 1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1, curr = 0;
        memset(dp,-1,sizeof(dp));
        return solve(nums, prev, curr);
    }
};