class Solution {
public:
    int lcs(string &s1,string &s2){
        int dp[501][501];
        memset(dp,0,sizeof(dp));
        int n=s1.length();
        int m=s2.length();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        string  v=s;
        reverse(v.begin(),v.end());
        int n=lcs(s,v);
        return s.length()-n;
    }
};