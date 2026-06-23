class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));
        long long count = 0;
        if (grid[0][0] > k) {
            return 0;
        } else {
            count = 1;
        }
        prefix[0][0] = grid[0][0];
        // first row
        for (int i = 1; i < grid[0].size(); i++) {
            prefix[0][i] = prefix[0][i - 1] + grid[0][i];
            if (prefix[0][i] <= k) {
                count++;
            }
        }
        // first collumn
        for (int i = 1; i < grid.size(); i++) {
            prefix[i][0] = prefix[i - 1][0] + grid[i][0];
            if (prefix[i][0] <= k) {
                count++;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                               prefix[i - 1][j - 1] + grid[i][j];
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (prefix[i][j] <= k) {
                    count++;
                } 
            }
        }
        return count;
    }
};