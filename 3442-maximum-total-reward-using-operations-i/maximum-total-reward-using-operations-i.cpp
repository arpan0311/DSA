class Solution {
public:
    int dp[4004][4004];
    long long arpan(vector<int>&nums,int i,long long x){
        if(i==nums.size()){
            return 0;
        }
        // overlaping subproblem 
       if(dp[i][x]!=-1){
        return dp[i][x];
       }
        // not take 
        int not_take=arpan(nums,i+1,x);
        int take=0;
        if(nums[i]>x){
            take=nums[i]+arpan(nums,i+1,x+nums[i]);
            not_take=arpan(nums,i+1,x);
        }
        return  dp[i][x] =max(take,not_take);
    }
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return arpan(nums,0,0);
    }
};