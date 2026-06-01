class Solution {
public:
int dp[1001];
int solve(vector<int>&nums,int i,int &k){
    if(i==nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    unordered_map<int,int>hash;
    int answer=INT_MAX;
    int trim=0;
    for(int j=i;j<nums.size();j++){
        hash[nums[j]]++;

        if(hash[nums[j]]==2){
            trim+=2;
        }
        else if(hash[nums[j]]>2){
            trim+=1;
        }
        answer=min(answer,k+trim+solve(nums,j+1,k));
    }
    return dp[i]=answer;
}
    int minCost(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,k);
    }
};