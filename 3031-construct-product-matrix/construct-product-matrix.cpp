class Solution {
public:
    const int mod = 12345;
    using ll = long long;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int size = m * n;
        vector<ll> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = grid[i / n][i % n] % mod;
        }
        vector<ll> ans(size, 1);

        ll prefix = 1;
        for (int i = 0; i < size; i++) {
            ans[i] = prefix;
            prefix = (prefix * arr[i]) % mod;
        }

        ll suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            ans[i] = (ans[i] * suffix) % mod;
            suffix = (suffix * arr[i]) % mod;
        }
        for (int i = 0; i < size; i++) {
            grid[i / n][i % n] = ans[i];
        }

        return grid;
    }
};