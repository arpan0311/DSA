class Solution {
public:
int dp[1001][1001];
  int solve(vector<int>& nums, int val, int prev, int i) {
    if (i == (int)nums.size()) {
        return (prev == (int)nums.size() - 1) ? 0 : INT_MIN;
    }
    if(dp[i][prev]!=-1){
        return dp[i][prev];
    }
    int take = INT_MIN;
    if (abs(nums[prev] - nums[i]) <= val) {
        int sub = solve(nums, val, i, i + 1);
        if (sub != INT_MIN) take = 1 + sub;
    }
    int not_take = solve(nums, val, prev, i + 1);

    return dp[i][prev]=max(take, not_take);
}
    int maximumJumps(vector<int>& nums, int target) {
        // base case
        if (nums.size() == 1) {
            return 0;
        }
        int prev = 0, i = 1;
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums, target, prev, i);
        if (ans <= 0) {
            return -1;
        }
        return ans;
    }
};