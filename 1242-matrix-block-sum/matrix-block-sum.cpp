class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> answer(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> row;
                for (int s = i - k; s <= i + k; s++) {
                    if (s >= 0 && s < n) {
                        row.push_back(s);
                    }
                }
                vector<int> col;
                for (int s = j - k; s <= j + k; s++) {
                    if (s >= 0 && s < m) {
                        col.push_back(s);
                    }
                }
                long long sum = 0;
                for (int s = 0; s < row.size(); s++) {
                    for (int c = 0; c < col.size(); c++) {
                        sum += mat[row[s]][col[c]];
                    }
                }
                answer[i][j] = sum;
            }
        }

        return answer;
    }
};