class Solution {
public:
    int dp[1001][1001];
    int arpan(string &s1,string &s2,int i,int j){
        if(i>=s1.length()||j>=s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        if(s1[i]==s2[j]){
            take=1+arpan(s1,s2,i+1,j+1);
        }
        int skips1=arpan(s1,s2,i+1,j);
        int skips2=arpan(s1,s2,i,j+1);
        return dp[i][j]=max(take,max(skips1,skips2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return arpan(text1,text2,0,0);
    }
};