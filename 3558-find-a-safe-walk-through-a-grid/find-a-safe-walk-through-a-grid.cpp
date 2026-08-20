class Solution {
public:
    int dp[51][51][102];
    bool solve(vector<vector<int>>& grid, int i, int j, int cnt,
               vector<vector<bool>>& vis) {
        // base case
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            vis[i][j]) {
            return false;
        }
        if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
        }
        // health
        cnt -= grid[i][j];
        if (cnt < 1) {
            return false;
        }
        
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }
        vis[i][j] = true;
        bool up = false, down = false, left = false, right = false;
        up = solve(grid, i - 1, j, cnt, vis);
        down = solve(grid, i + 1, j, cnt, vis);
        left = solve(grid, i, j - 1, cnt, vis);
        right = solve(grid, i, j + 1, cnt, vis);

        vis[i][j] = false;
        cnt += grid[i][j];
        return dp[i][j][cnt]= up || down || left || right;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        memset(dp,-1,sizeof(dp));
        return solve(grid, 0, 0, health, vis);
    }
};