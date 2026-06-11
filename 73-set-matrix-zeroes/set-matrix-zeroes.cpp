class Solution {
public:
    void solve(vector<pair<int, int>>& answer, vector<vector<int>>& mat) {
        for (auto& it : answer) {
            int i = it.first;
            int j = it.second;
            for (int k = 0; k < mat.size(); k++) {
                mat[k][j] = 0;
            }
            for (int k = 0; k < mat[0].size(); k++) {
                mat[i][k] = 0;
            }
        }
    }
        void setZeroes(vector<vector<int>> & matrix) {
            vector<pair<int, int>> container;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == 0) {
                        container.push_back({i, j});
                    }
                }
            }
            solve(container, matrix);
        }
    };