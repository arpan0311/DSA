class Solution {
public:
    int dp[201][20001];
    bool arpan(vector<int>&nums,int i,int curr,int sum,bool &check){
        if(check){
            return true;;
        }
        if(i>=nums.size()){
            return false;
        }
        if(curr>sum){
            return false;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        if(2*curr==sum){
            check=true;
            return true;
        }
        bool take=arpan(nums,i+1,curr+nums[i],sum,check);
        bool not_take=arpan(nums,i+1,curr,sum,check);
        dp[i][curr]=take||not_take;
        return dp[i][curr];
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int i=0;
        int curr=0;
        bool check=false;
        
        return arpan(nums,i,curr,sum,check);
    }
};