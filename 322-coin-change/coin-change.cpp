class Solution {
public:
    // ind target
    // int dp[13][10001];
    // int solve(vector<int>& nums, int i, int target) {
    //     // already le liya
    //     if (target == 0) {
    //         return 0;
    //     }
    //     if (i < 0) {
    //         return INT_MAX-target;
    //     }
    //     if(dp[i][target]!=-1){
    //         return dp[i][target];
    //     }
    //     int not_take =  solve(nums, i - 1, target);
    //     int take = INT_MAX;
    //     if (target - nums[i] >= 0) {
    //         int get=solve(nums,i,target-nums[i]);
    //        if(get!=INT_MAX){
    //             take=1+get;
    //        }
    //     }
        
    //     dp[i][target]= min(take, not_take);
    //     return dp[i][target];
    // }
    // int coinChange(vector<int>& coins, int amount) {
        // if(amount==0){
        //     return 0;
        // }
        // sort(coins.begin(),coins.end());
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(coins, coins.size()-1, amount);
        // if(ans>10000){
        //     return -1;
        // }
        // return ans;

//         // top down 
//         int dp[coins.size()+1][amount+1];
//         dp[0][0]=1;
//         // base condition 
//         for(int i=0;i<=target;i++){
//             dp[0][target]=1;
//         }
//         for(int i=0;i<coins.size();i++){
//             for(int j=1;j<=amount;j++){
//                 int take=INT_MAX,
//                 take=1+dp[i][j-1];
//                 int nottake=dp[i][j-1];
//                 dp[i][j]=max(take,nottake);
//             }
//         }
//         return dp[coins.size()][amount];
//     }
// };
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e9));

    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            int nottake = dp[i-1][j];
            int take = 1e9;
            if(j >= coins[i-1]){
                take = 1 + dp[i][j - coins[i-1]];
            }
            dp[i][j] = min(take, nottake);
        }
    }

    return dp[n][amount] >= 1e9 ? -1 : dp[n][amount];
}
};