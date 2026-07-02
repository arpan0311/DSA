class Solution {
public:
    void solve(vector<vector<int>>& board, int i, int j,vector<vector<int>>&answer) {
        int live = 0;


// Top
if (i - 1 >= 0 && board[i - 1][j] == 1)
    live++;

// Bottom
if (i + 1 < board.size() && board[i + 1][j] == 1)
    live++;

// Left
if (j - 1 >= 0 && board[i][j - 1] == 1)
    live++;

// Right
if (j + 1 < board[0].size() && board[i][j + 1] == 1)
    live++;

// Top Left
if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
    live++;

// Top Right
if (i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 1)
    live++;

// Bottom Left
if (i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 1)
    live++;

// Bottom Right
if (i + 1 < board.size() && j + 1 < board[0].size() &&
    board[i + 1][j + 1] == 1)
    live++;
        // ---------- Updating the SAME board ----------

        if (board[i][j] == 0) {

            // Dead cell
            if (live == 3) {
                answer[i][j] = 1;
            }

        } else {

            // Live cell
            if (live < 2 || live > 3) {
                answer[i][j] = 0;
            } else {
                answer[i][j] = 1;
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board) {

        // Traversing the board
        vector<vector<int>>answer=board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                // Passing the SAME board to solve()
                solve(board, i, j,answer);
            }
        }
        board=answer;
    }
};