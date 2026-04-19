class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int inicolor, 
             int rows[], int cols[], vector<vector<int>>& ans, int newcolor) {
        // mark the current cell with the new color
        ans[row][col] = newcolor;

        int n = image.size();
        int m = image[0].size();

        // explore 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + rows[i];
            int ncol = col + cols[i];

            // check boundaries + same initial color + not already colored
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor) {
                dfs(image, nrow, ncol, inicolor, rows, cols, ans, newcolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image; // make a copy

        int rows[4] = {-1, 0, 1, 0};   // row directions
        int cols[4] = {0, 1, 0, -1};   // col directions

     
            dfs(image, sr, sc, inicolor, rows, cols, ans, color);
        

        return ans;
    }
};
