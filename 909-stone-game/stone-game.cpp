class Solution {
public:
    int dp[501][501];
    int total_sum;
    int solve(vector<int>&nums,int i,int n){
        // base case
        if(i>n){
            return 0;
        }
        if(i==n){
            return nums[i];
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int alice=nums[i]+max(solve(nums,i+1,n-1),solve(nums,i+2,n));
        int bob=nums[n]+max(solve(nums,i,n-2),solve(nums,i,n-1));
        return dp[i][n]=max(alice,bob);
    }
    bool stoneGame(vector<int>& nums) {
        total_sum=accumulate(nums.begin(),nums.end(),0);
        int i=0,n=nums.size();
        memset(dp,-1,sizeof(dp));
        int curr_sum=solve(nums,i,n-1);
        return (curr_sum>total_sum/2);
    }
};