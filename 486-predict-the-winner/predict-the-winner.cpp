class Solution {
public:
int dp[23][23];
    int solve(int i,int j,vector<int>&nums){
        // base condition 
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // tune apna best le ;iya ab 2nd wala player jaan laga dega terko minimize karegaaaaa 
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
     int total_0 = accumulate(nums.begin(), nums.end(), 0);
     memset(dp,-1,sizeof(dp));
        int first= solve(0,n-1,nums);
        return first>=total_0-first;
    }
};