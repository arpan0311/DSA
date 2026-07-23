class Solution {
public:
    int dp[205][205];
    int solve(int left,int right){
        if(left>=right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int answer=INT_MAX;
        // agar woh optimaly play kare to ek option hoga ya to left ya right 
        for(int i=left;i<=right;i++){
            answer=min(answer,(i+max(solve(left,i-1),solve(i+1,right))));
        }
        return dp[left][right]=answer;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};