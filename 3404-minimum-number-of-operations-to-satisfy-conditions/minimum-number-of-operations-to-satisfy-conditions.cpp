class Solution {
public:
int dp[1001][10];
    int solve(int j,int keep,vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        if(j>=m){
            return 0;
        }
        if(dp[j][keep]!=-1){
            return dp[j][keep];
        }
        int answer=INT_MAX;
        int cnt=0;
        // check all rows 
        for(int i=0;i<n;i++){
            if(grid[i][j]==keep){
                continue;
            }
            cnt+=1;
        }
        // move to next collumn with corrosponding count value...
        for(int op1=0;op1<=9;op1++){
            if(op1==keep){
                continue;
            }
            answer=min(answer,cnt+solve(j+1,op1,grid));
        }
        return dp[j][keep]=answer;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        // I have to make all the collumn same and make sure different from right side 

        int ans=INT_MAX;
        int n=grid.size(),m=grid[0].size();

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<=9;i++){
            ans=min(ans,solve(0,i,grid));
        }

        return ans;
    }   
};