class Solution {
public:
#define ll long long
    ll dp[5001][301];
    // const ll mod = 1e9 + 7;/
    ll arpan(vector<int>& nums, ll sum, int ind) {
        if (sum == 0)
            return 1;
        if (sum < 0)
            return 0;

        if (dp[sum][ind] != -1)
            return dp[sum][ind];

        ll ways = 0;

        for (int i = ind; i < nums.size(); i++) {
            if (sum - nums[i] >= 0) {
                ways = (ways + arpan(nums, sum - nums[i], i)) ;
            }
        }

        return dp[sum][ind] = ways;
    }
    int change(int sum, vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return arpan(nums, sum, 0);
    }
};