class Solution {
public:
int dp[1001];
    int  arpan(vector<int>&cost,int i){

        if(i>=cost.size()){
            return 0;
        } 
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=cost[i]+arpan(cost,i+1);
        int two=cost[i]+arpan(cost,i+2);
        dp[i]=min(one,two);
        return dp[i];
    }   
    int minCostClimbingStairs(vector<int>& cost) {
        int i=0,sum=0,mini=INT_MAX;
        memset(dp,-1,sizeof(dp));
        int zero=arpan(cost,i);
        int one=arpan(cost,i+1);
        return min(zero,one);
    }
};