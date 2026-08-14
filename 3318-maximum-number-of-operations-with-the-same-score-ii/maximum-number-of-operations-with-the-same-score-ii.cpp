class Solution {
public:
    int dp[2001][2001];
    int solve(vector<int>& nums, int i, int j, int curr) {
        if (i >= j) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take = 0, not_take = 0, from_last = 0;
        if (i + 1 <= j && nums[i] + nums[i + 1] == curr) {
            take = 1 + solve(nums, i + 2, j, curr);
        }

        if (nums[i] + nums[j] == curr) {
            not_take = 1 + solve(nums, i + 1, j - 1, curr);
        }

        if (j - 1 >= i && nums[j] + nums[j - 1] == curr) {
            from_last = 1 + solve(nums, i, j - 2, curr);
        }
        return dp[i][j]=max(max(take, not_take), from_last);
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0] + nums[n - 1];
        memset(dp,-1,sizeof(dp));
        int take = 1 + solve(nums, 1, n - 2, curr);
        curr = nums[0] + nums[1];
        int not_take = 1 + solve(nums, 2, n - 1, curr);
        curr = nums[n - 2] + nums[n - 1];
        int leave = 1 + solve(nums, 0, n - 3, curr);
        return  max(max(take, not_take), leave);
    }
};