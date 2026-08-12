class Solution {
public:
int N;
int dp[46];
    int reach(int i){
        if(i==N){
            return 1;
        }
        if(i>N){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int oneStep=reach(i+1);
        int twoStep=reach(i+2);
        return dp[i]=oneStep+twoStep;
    }
    int climbStairs(int n) {    
        N=n;
        memset(dp,-1,sizeof(dp));
        return reach(0);
    }
};