class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>&grid,int i,int j,int &answer){
        if(i>=grid.size()||j>=grid[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
         if(grid[i][j]==1){
            return 0;
        }
        if(i==grid.size()-1&&j==grid[0].size()-1){
            //  answer++;
            return 1;
        }

       int right= solve(grid,i+1,j,answer);
       int down= solve(grid,i,j+1,answer);
       dp[i][j]=right+down;
       return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid ) {
        int answer=0;
        int n=grid.size(),m=grid[0].size();  
         memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,answer);
         
    }
};