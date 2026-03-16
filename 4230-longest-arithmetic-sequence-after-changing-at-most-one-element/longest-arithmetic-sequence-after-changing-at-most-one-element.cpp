class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 2);
        vector<int> suffix(n, 2);
        for (int i = 2; i < n; i++) {
            if (nums[i - 2] - nums[i - 1] == nums[i - 1] - nums[i]) {
                prefix[i] = prefix[i - 1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i]) {
                suffix[i] = suffix[i + 1] + 1;
            }
        }
        int ans = 2;
        for (int i = 0; i < n; i++) {
            ans = max(ans, max(suffix[i], prefix[i]));
            if (i == 0) {
                ans = max(ans, 1 + suffix[i + 1]);
            } else if (i == n - 1) {
                ans = max(ans, 1 + prefix[i - 1]);
            } else {
                // check if any trend is going to follow
                if ((nums[i - 1] + nums[i + 1]) % 2 == 0) {

                    int mid = (nums[i - 1] + nums[i + 1]) / 2;
                    int diff = mid - nums[i - 1];

                    int left = 1;
                    int right = 1;

                    if (i >= 2 && nums[i - 1] - nums[i - 2] == diff)
                        left = prefix[i - 1];

                    if (i < n - 2 && nums[i + 2] - nums[i + 1] == diff)
                        right = suffix[i + 1];

                    ans = max(ans, left + right + 1);
                }
                ans = max(ans, 1 + suffix[i + 1]);
                ans = max(ans, 1 + prefix[i - 1]);
            }
        }
        return ans;
    }
};