class Solution {
public:
int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0,skip_i=0,skip_j=0;
        if(s1[i]==s2[j]){
            take=1+solve(s1,s2,i-1,j-1);
        }
        else{
            skip_i=solve(s1,s2,i-1,j);
            skip_j=solve(s1,s2,i,j-1);
        }
        return dp[i][j]= max(take,max(skip_i,skip_j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size()-1,j=text2.size();
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,i,j);
    }
};