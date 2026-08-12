class Solution {
public:
  int dp[1001][2001];
    int solve(vector<int>& nums, int i, int target, int sum) {

        if (i >= nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }
        // if (sum == target) {
        //     return 1;
        // }
        if(dp[i][sum+1000]!=-1){
            return dp[i][sum+1000];
        }
        int take = solve(nums, i + 1, target, sum + nums[i]);
        int not_take = solve(nums, i + 1, target, sum - nums[i]);
        return dp[i][sum+1000]=take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, target, 0);
    }
};