class Solution {
public:
// int dp[501][501];
//     int solve(string &s1,string &s2,int i,int j){
//         if(i<0){
//             return j+1;
//         }
//         if(j<0){
//             return i+1;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s1[i]==s2[j]){
//             return dp[i][j]=solve(s1,s2,i-1,j-1);
//         }
//         else{
//             // add replace delete 
//             return dp[i][j]=1+min(solve(s1,s2,i,j-1),min(solve(s1,s2,i-1,j-1),solve(s1,s2,i-1,j)));
//         }
//     }
    int minDistance(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // base case 
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
         for(int j=0;j<=n;j++){
            dp[j][0]=j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
};