class Solution {
public:
    int bfs(int s1, int s2, int e1, int e2) {

        vector<vector<bool>> vis(9, vector<bool>(9, false));

        queue<pair<pair<int, int>, int>> q;

        q.push({{s1, s2}, 0});
        vis[s1][s2] = true;

        int row[4] = {-1, -1, 1, 1};
        int col[4] = {-1, 1, 1, -1};

        while (!q.empty()) {

            int f = q.front().first.first;
            int s = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            if (e1 == f && e2 == s) {
                return steps;
            }

            for (int i = 0; i < 4; i++) {

                int new_row = f + row[i];
                int new_col = s + col[i];

                while (new_row >= 0 && new_row < 9 &&
                       new_col >= 0 && new_col < 9) {

                    if (!vis[new_row][new_col]) {

                        vis[new_row][new_col] = true;

                        q.push({{new_row, new_col}, steps + 1});
                    }

                    new_row += row[i];
                    new_col += col[i];
                }
            }
        }

        return -1;
    }

    int minBishopMoves(vector<int>& source, vector<int>& target) {
        return bfs(source[0], source[1],
                   target[0], target[1]);
    }
};