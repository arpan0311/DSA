class Solution {
public:
    int dp[101][101][3];
    int solve(vector<int>&nums,int idx,bool turn,int limit){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][limit][turn]!=-1){
            return dp[idx][limit][turn];
        }
        int val;
        if(turn){
            val=0;
        }
        else {
            val=INT_MAX;
        }
        int stone=0;
        for(int k=idx;k<min(idx+2*limit,(int)nums.size());k++){
            stone+=nums[k];
            int no_of_stone_taken=k-idx+1;
            if(turn){
                val=max(val,stone+solve(nums,k+1,!turn,max(limit,no_of_stone_taken)));
            }
            else{
                // why not adding curr_sum 
                // avoid curr_sum becouse it's bob's turn and add future sum leave these sums...
                val=min(val,solve(nums,k+1,!turn,max(limit,no_of_stone_taken)));
            }
        }
        return dp[idx][limit][turn]=val;
    }
    int stoneGameII(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,true,1);
    }
};