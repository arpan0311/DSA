class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int curr_row = drow[k] + i;
            int curr_col = dcol[k] + j;
            if (curr_row >= 0 && curr_row < board.size() &&    
                curr_col >= 0 && curr_col < board[0].size() &&
                !vis[curr_row][curr_col] && board[curr_row][curr_col] == 'O') {  
                dfs(board, curr_row, curr_col, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // first row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O')       
                dfs(board, 0, j, vis);
        }
        // first column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O')        
                dfs(board, i, 0, vis);
        }
        // last row
        for (int j = 0; j < m; j++) {
            if (!vis[n-1][j] && board[n-1][j] == 'O')   
                dfs(board, n-1, j, vis);
        }
        // last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][m-1] && board[i][m-1] == 'O')  
                dfs(board, i, m-1, vis);
        }

        // flip unvisited O's to X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';                   
                }
            }
        }
    }
};