class Solution {
public:
    int dp[301][5001];
    int solve(vector<int>&coins,int amount,int i){
        if(i>=coins.size()){
            if(amount==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=0;
        if(coins[i]<=amount){
            take=solve(coins,amount-coins[i],i);
        }
        int notTake=solve(coins,amount,i+1);
        return dp[i][amount]= take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount,0);
    }
};