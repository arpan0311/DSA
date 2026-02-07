class Solution {
public:
    int dp[201][10001];
    bool arpan(vector<int>&nums,int i,int target){
        if(target==0){
            return true;
        }
        if(i<0||target<0){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=false;
        if(nums[i]<=target){
            take=arpan(nums,i-1,target-nums[i]);
        }
        bool not_take=arpan(nums,i-1,target);
        return dp[i][target]= take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        // simple h 
        int target=0;

        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        memset(dp,-1,sizeof(dp));
        if(target%2!=0){
            return false;
        }
        target=target/2;
        int i=nums.size()-1;
       return arpan(nums,i,target);
    }
};