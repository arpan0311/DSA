class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '.'));

        int i = 0;
        while (i < m - 1) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = '#';
            }
            i++;
        }

        return grid;
    }
};