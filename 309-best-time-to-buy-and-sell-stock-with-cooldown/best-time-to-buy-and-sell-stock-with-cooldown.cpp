class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                // can buy
                int take=0,nottake=0;
               if(j==1){
                // buy
                take=-nums[i]+dp[i+1][0];
                nottake=dp[i+1][1];
               }
               else{
                take=nums[i]+dp[i+2][1];
                nottake=dp[i+1][0];
               }
               dp[i][j]=max(take,nottake);
            }
        }
        return dp[0][1];
    }
};