class Solution {
public:
    int m, n;
    typedef long long ll;
    const int mod = 1e9 + 7;
    vector<vector<pair<ll,ll>>>dp;
    pair<ll, ll> solve(vector<vector<int>>& grid, int i, int j) {
        if (i == m-1 && j == n-1 ) {
            return {grid[i][j], grid[i][j]};
        }


  if(dp[i][j].first != LLONG_MIN){
    return dp[i][j];
}
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (i + 1 < grid.size()) {
            auto [downMax, downMin] = solve(grid, i + 1, j);
            maxVal =
                max(maxVal, max(grid[i][j] * downMax, grid[i][j] * downMin));
            minVal =
                min(minVal, min(grid[i][j] * downMax, grid[i][j] * downMin));
        }

        if (j + 1 < grid[0].size()) {
            auto [downMax, downMin] = solve(grid, i, j + 1);
            maxVal =
                max(maxVal, max(grid[i][j] * downMax, grid[i][j] * downMin));
            minVal =
                min(minVal, min(grid[i][j] * downMax, grid[i][j] * downMin));
        }
        return dp[i][j]={maxVal,minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int i = 0, j = 0;
       m = grid.size();
    n = grid[0].size();
    dp = vector<vector<pair<ll,ll>>>(m, vector<pair<ll,ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [downMax, downMin] = solve(grid, i, j);
        long long answer = max(downMax, downMin);
    //    dp = vector<vector<pair<ll,ll>>>(m, vector<pair<ll,ll>>(n, {LLONG_MIN, LLONG_MAX}));
        if (answer < 0) {
            return -1;
        }
        return answer % mod;
    }
};