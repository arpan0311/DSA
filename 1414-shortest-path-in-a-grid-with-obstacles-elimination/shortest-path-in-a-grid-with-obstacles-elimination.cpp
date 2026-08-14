class Solution {
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;

        int i = 0, j = 0;
        q.push({i, j, k});

        bool vis[41][41][1601];
        memset(vis, false, sizeof(vis));

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                vector<int> temp = q.front();
                q.pop();

                int x = temp[0], y = temp[1], newK = temp[2];

                if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                    return steps;
                }

                for (auto& it : dir) {
                    int new_i = it[0] + x;
                    int new_j = it[1] + y;

                    if (new_i < 0 || new_i >= grid.size() ||
                        new_j < 0 || new_j >= grid[0].size()) {
                        continue;
                    }

                    if (grid[new_i][new_j] == 0 &&
                        !vis[new_i][new_j][newK]) {

                        q.push({new_i, new_j, newK});
                        vis[new_i][new_j][newK] = true;
                    }
                    else if (grid[new_i][new_j] == 1 &&
                             newK > 0 &&
                             !vis[new_i][new_j][newK - 1]) {

                        q.push({new_i, new_j, newK - 1});
                        vis[new_i][new_j][newK - 1] = true;
                    }
                }
            }

            steps++;
        }
        return -1;
    }
};