class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&nums,int i,int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // we have to win 
        int take_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int take_j=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));
        return  dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& nums) {
       int total = accumulate(nums.begin(), nums.end(), 0);
       
       int n=nums.size()-1;
       memset(dp,-1,sizeof(dp));
        int alice=solve(nums,0,n);
        return alice>total-alice;
    }
};