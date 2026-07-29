class Solution {
public:
int dp[10000];
    int solve(int i, vector<int>& nums) {
        if (i >= nums.size() - 1) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {
            if (solve(i + j, nums) != INT_MAX) {
                maxi = min(maxi, 1 + solve(i + j, nums));
            }
        }
        return dp[i]=maxi;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
         return solve(0, nums); }
};