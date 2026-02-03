class Solution {
public:
    // ind target
    int dp[13][10001];
    int solve(vector<int>& nums, int i, int target) {
        // already le liya
        if (target == 0) {
            return 0;
        }
        if (i < 0) {
            return INT_MAX-target;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take =  solve(nums, i - 1, target);
        int take = INT_MAX;
        if (target - nums[i] >= 0) {
            int get=solve(nums,i,target-nums[i]);
           if(get!=INT_MAX){
                take=1+get;
           }
        }
        
        dp[i][target]= min(take, not_take);
        return dp[i][target];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof(dp));
        int ans=solve(coins, coins.size()-1, amount);
        if(ans>10000){
            return -1;
        }
        return ans;
    }
};