class Solution {
public:
int n,m;
    int solve(vector<vector<int>>&grid,int i,int j,int step,int obs){
        // out of bound
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0){
            return 0;
        }
        // reached
        if(grid[i][j]==2 && step==n*m-obs-1){
            return 1;
        }
        else if(grid[i][j]==2){
            return 0;
        }
        // mark
        if(grid[i][j]==-2){
            return 0;
        }
        // obstacle
        if(grid[i][j]==-1){
            return 0;
        }
        grid[i][j]=-2;
        int up=solve(grid,i+1,j,step+1,obs);
        int down=solve(grid,i,j+1,step+1,obs);
        int left=solve(grid,i-1,j,step+1,obs);
        int right=solve(grid,i,j-1,step+1,obs);
        grid[i][j]=0;
        int ans=up+left+right+down;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        int obs=0;
          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-1){
                    obs++;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int step=0;
                    // grid[i][j]=0;/
                    return solve(grid,i,j,step,obs);
                }
            }
        }
        return -1;
    }
};