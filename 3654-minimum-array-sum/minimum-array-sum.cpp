class Solution {
public:
    int dp[101][101][101];

    int solve(vector<int>& nums, int k, int op1, int op2, int i) {
        if (i == nums.size()) return 0;

        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];

        int val = nums[i];
        int mini = INT_MAX;

        // skip
        mini = min(mini, val + solve(nums, k, op1, op2, i + 1));

        // operation 1
        if (op1 > 0) {
            int temp = (val + 1) / 2;
            mini = min(mini, temp + solve(nums, k, op1 - 1, op2, i + 1));
        }

        // operation 2
        if (op2 > 0 && val - k >= 0) {
            int temp = val - k;
            mini = min(mini, temp + solve(nums, k, op1, op2 - 1, i + 1));
        }

        // both operations
        if (op1 > 0 && op2 > 0) {

            // op1 then op2
            int temp1 = (val + 1) / 2;
            if (temp1 - k >= 0) {
                mini = min(mini,
                    (temp1 - k) + solve(nums, k, op1 - 1, op2 - 1, i + 1));
            }

            // op2 then op1
            if (val - k >= 0) {
                int temp2 = (val - k + 1) / 2;
                mini = min(mini,
                    temp2 + solve(nums, k, op1 - 1, op2 - 1, i + 1));
            }
        }

        return dp[i][op1][op2] = mini;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, k, op1, op2, 0);
    }
};