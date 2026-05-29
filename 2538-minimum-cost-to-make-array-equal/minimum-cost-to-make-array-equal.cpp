class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& cost, int target) {
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans += 1LL * abs((long long)nums[i] - target) * cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(),nums.end()), high = *max_element(nums.begin(),nums.end());
        long long res = LLONG_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long value = solve(nums, cost, mid);
            long long maxi = LLONG_MAX;
            if (mid + 1 <=high) {
                maxi = solve(nums, cost, mid+1);
            }
            res = min(res, min(value, maxi));
            if (maxi < value) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};