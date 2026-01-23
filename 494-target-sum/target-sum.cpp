class Solution {
public:
    long long arpan(vector<int>& nums, int i, int target, int sum) {
        if (i == nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }
        if (i > nums.size()) {
            return 0;
        }
        long long plus = arpan(nums, i + 1, target, sum + nums[i]);
        long long minus = arpan(nums, i + 1, target, sum - nums[i]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int i = 0;
        int sum = 0;

        return arpan(nums, i, target, sum);
    }
};