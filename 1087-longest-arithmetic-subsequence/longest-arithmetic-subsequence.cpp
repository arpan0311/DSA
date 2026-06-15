class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&nums,int ind,int diff,unordered_map<int,int>dp[]){
        if(ind-1<0){
            return 0;
        }
        if(dp[ind].count(diff)){
            return dp[ind][diff];
        }
        int ans=0;
        for(int j=ind-1;j>=0;j--){
            if(nums[ind]-nums[j]==diff){
                ans=max(ans,1+solve(nums,j,diff,dp));
            }
        }
        return dp[ind][diff]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int max_val=0;
        unordered_map<int,int>dp[n+1];
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                max_val = max(max_val,
              2 + solve(nums,i,nums[j]-nums[i],dp));
            }
        }
        return max_val;
    }
};