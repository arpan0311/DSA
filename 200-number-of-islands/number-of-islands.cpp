class Solution {
public:
    void solve(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]||grid[i][j]=='0'){
            return;
        }
        vis[i][j]=true;
        solve(grid,vis,i+1,j);
        solve(grid,vis,i-1,j);
        solve(grid,vis,i,j+1);
        solve(grid,vis,i,j-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    solve(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};