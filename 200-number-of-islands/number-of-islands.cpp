class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<bool>>& vis) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] != '1'||vis[i][j]==true) {
            return;
        }
        // valid hai...
        vis[i][j] = true;

        dfs(grid, i + 1, j, vis);
        dfs(grid, i, j + 1, vis);
        dfs(grid, i - 1, j, vis);
        dfs(grid, i, j - 1, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j, vis);
                }
            }
        }

        return cnt;
    }
};