class Solution {
public:
    // int dp[201][10001];
    // bool arpan(vector<int>&nums,int i,int target){
    //     if(target==0){
    //         return true;
    //     }
    //     if(i<0||target<0){
    //         return false;
    //     }
    //     if(dp[i][target]!=-1){
    //         return dp[i][target];
    //     }
    //     bool take=false;
    //     if(nums[i]<=target){
    //         take=arpan(nums,i-1,target-nums[i]);
    //     }
    //     bool not_take=arpan(nums,i-1,target);
    //     return dp[i][target]= take||not_take;
    // }
    bool canPartition(vector<int>& nums) {
        // simple h 
        // int target=0;

        // for(int i=0;i<nums.size();i++){
        //     target+=nums[i];
        // }
        // memset(dp,-1,sizeof(dp));
        // if(target%2!=0){
        //     return false;
        // }
        // tabulation code 
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0){
            return false;
        }
        target=target/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        for(int i=0;i<=nums.size();i++){
            dp[i][0]=1;//true
        }
        for(int i=1;i<=target;i++){
            dp[0][i]=0;//false
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=target;j++){
                int take=0;
                if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
                }
                int not_take=dp[i-1][j];
                dp[i][j]=take||not_take;
            }
        }
    //    return arpan(nums,i,target);
    return dp[nums.size()][target];
    }
};