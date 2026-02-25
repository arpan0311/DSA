class Solution {
public:
    int dp[1001][101][2];
    int arpan(int k,vector<int>&prices,bool canbuy,int i){
        if(k==0){
            return 0;
        }
        if(i==prices.size()){
            return  0;
        }
        if(dp[i][k][canbuy]!=-1){
            return dp[i][k][canbuy];
        }
        // canbuy 
        int take=0,nottake=0;
        if(canbuy){
            take=-prices[i]+arpan(k,prices,false,i+1);
            nottake=arpan(k,prices,canbuy,i+1);
        }
        else{
            take=prices[i]+arpan(k-1,prices,true,i+1);
            nottake=arpan(k,prices,false,i+1);
        }
        return dp[i][k][canbuy] = max(take,nottake);

    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return arpan(k,prices,true,0);
    }
};