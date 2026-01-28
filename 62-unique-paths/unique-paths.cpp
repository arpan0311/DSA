class Solution {
public:
    int dp[101][101];
    int arpan(vector<vector<int>>& ans, int i, int j, int& count) {
        if (i <  0 || j < 0) {
            return 0;
        }
        if (i == 0 && j == 0 ) {
            return 1;
        }
        if (ans[i][j] !=-1) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0,nottake=0;
        if (i - 1 >=0 && ans[i - 1][j] == -1) {
            ans[i][j] = 0;
          take=arpan(ans, i - 1, j, count);
           ans[i][j]=-1;
        }
      
        if (j - 1 >=0  && ans[i][j - 1] == -1) {
            ans[i][j] = 0;
            nottake=arpan(ans, i, j - 1, count);
            ans[i][j]=-1;
        }
        dp[i][j]=take+nottake;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int count = 0;
        int i = m-1, j = n-1;
        memset(dp,-1,sizeof(dp));
         return arpan(ans, i, j, count);

        //  tabulation kaise karu I will have to 

        
    }
};