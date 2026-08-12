class Solution {
public:
int dp[1000];
    int solve(int n,int i,vector<int>& cost){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=cost[i]+solve(n,i+1,cost);
        int two=cost[i]+solve(n,i+2,cost);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(n,0,cost),solve(n,1,cost));
    }
};