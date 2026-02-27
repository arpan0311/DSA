class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>&nums,int i,bool canbuy){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][canbuy]!=-1){
            return dp[i][canbuy];
        }
        int take=0,nottake=0;
        // buy 
        if(canbuy){
            take=-nums[i]+solve(nums,i+1,false);
            nottake=solve(nums,i+1,true);
            
        }
        else{
            take=nums[i]+solve(nums,i+2,true);
            nottake=solve(nums,i+1,false);
        }
        return dp[i][canbuy]=max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,true);
    }
};