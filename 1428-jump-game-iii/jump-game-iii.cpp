class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(vector<int>& nums, int i, vector<bool>& vis) {
        if (i < 0 || i >= n) {
            return false;
        }

        if (nums[i] == 0) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        vis[i] = true;
        bool x = false;
        if (i + nums[i] < n && !vis[i + nums[i]]) {
            // vis[i + nums[i]] = true;
            x = solve(nums, i + nums[i], vis);
        }

        bool y = false;
        if (i - nums[i] >= 0 && !vis[i - nums[i]]) {
            // vis[i - nums[i]] = true;
            y = solve(nums, i - nums[i], vis);
        }

        return dp[i] = x || y;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        n = arr.size();
        dp.assign(n, -1);

        return solve(arr, start, vis);
    }
};