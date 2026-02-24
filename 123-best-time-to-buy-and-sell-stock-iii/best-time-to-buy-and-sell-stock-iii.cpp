class Solution {
public:
    // int dp[10001][3][2];
    // int arpan(vector<int>&prices,int i,int limit,bool canbuy){
    //     // can't
    //     if(limit==2){
    //         return 0;
    //     }
    //     if(i>=prices.size()){
    //         return 0;
    //     }
    //     if(dp[i][limit][canbuy]!=-1){
    //         return dp[i][limit][canbuy];
    //     }
    //     // 2 case banege
    //     int take=0,nottake=0;
    //     if(canbuy){
    //         // buy at most 2 times buy
    //         take=-prices[i]+arpan(prices,i+1,limit,false);
    //         nottake=arpan(prices,i+1,limit,canbuy);
    //     }
    //     else{
    //         take=prices[i]+arpan(prices,i+1,limit+1,true);
    //         nottake=arpan(prices,i+1,limit,canbuy);
    //     }
    //     return dp[i][limit][canbuy]=max(take,nottake);
    // }
    int maxProfit(vector<int>& prices) {
        //     int i=0,limit=0;
        //     bool canbuy=true;
        //     memset(dp,-1,sizeof(dp));
        //    return arpan(prices,i,limit,canbuy);
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    
        // base condition
        // capacity 0;
       for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dp[i][j][0]=0;
        }
       }

        for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            dp[n][i][j]=0;
        }
       }

        for (int i = n - 1; i >= 0; i--) {
            // for can buy or not
            for (int j = 0; j < 2; j++) {
                for (int k = 1; k < 3; k++) {
                    int take=0,nottake=0;
                    if (j==1) {
                        take = -prices[i] + dp[i + 1][0][k];
                        nottake = dp[i + 1][1][k];
                    } else {
                        // have to decrese the value of k
                        take = prices[i] + dp[i + 1][1][k-1];
                        nottake = dp[i + 1][0][k];
                    }
                    dp[i][j][k] = max(take, nottake);
                }
            }
        }
        return dp[0][1][2];
    }
};