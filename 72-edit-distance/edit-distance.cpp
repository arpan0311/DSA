class Solution {
public:
int dp[501][501];
    int solve(string &s1,string &s2,int i,int j){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i-1,j-1);
        }
        else{
            // add replace delete 
            return dp[i][j]=1+min(solve(s1,s2,i,j-1),min(solve(s1,s2,i-1,j-1),solve(s1,s2,i-1,j)));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,n-1,m-1);
    }
};