class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layer = min(m , n )/2;

        for (int i = 0; i < layer; i++) {
            // all four...
            int top = i, bottom = grid.size() - 1 - i, left = i,
                right = grid[0].size() - 1 - i;
            // topRow
            vector<int> row;
            for (int j = left; j <= right; j++) {
                row.push_back(grid[top][j]);
            }

            for (int j = top+1; j < bottom; j++) {
                row.push_back(grid[j][right]);
            }

            for (int j = right; j >= left; j--) {
                row.push_back(grid[bottom][j]);
            }

            for (int j = bottom - 1; j >= top + 1; j--) {
                row.push_back(grid[j][left]);
            }

            int t = k % row.size();
            rotate(begin(row), begin(row) + t, end(row));
            int idx=0;
            for (int j = left; j <= right; j++) {
                grid[top][j] = row[idx];
                idx++;
            }

            for (int j = top + 1; j <= bottom - 1; j++) {
                grid[j][right] = row[idx];
                idx++;
            }

           
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = row[idx];
                idx++;
            }

       
            for (int j = bottom - 1; j >= top + 1; j--) {
                grid[j][left] = row[idx];
                idx++;
            }
        }
    

    return grid;
}
}
;