class Solution {
public:
  int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        if(i>=s1.length()||j>=s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int same=0;
        if(s1[i]==s2[j]){
          same= 1+ solve(s1,s2,i+1,j+1);
        }
        int notsame=solve(s1,s2,i+1,j);
        int go=solve(s1,s2,i,j+1);
        dp[i][j]=max(same,max(notsame,go));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0,j=0;
        memset(dp,-1,sizeof(dp));
        
        return solve(text1,text2,i,j);
    }
    int longestPalindromeSubseq(string s) {
        string ans=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(ans,s);
    }
};