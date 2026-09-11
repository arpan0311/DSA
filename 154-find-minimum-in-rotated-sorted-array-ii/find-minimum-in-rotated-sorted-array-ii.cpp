class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = nums.size() - 1;
        int last = nums[high];
        int ans = min(nums[0], nums[n - 1]);
        while (low <= high) {
            while (low < high && nums[low] == nums[low + 1]) {
                low++;
            }
            while (high > low && nums[high] == nums[high - 1]) {
                high--;
            }
            int mid = low + (high - low) / 2;
            ans = min(ans, nums[mid]);
            // incresing pattern hain
            if (nums[mid] < last) {
                if (mid - 1 >= 0 && mid + 1 <= n - 1 &&
                    nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                    return nums[mid];
                } else {
                    high = mid - 1;
                }

            } else {

                if (mid - 1 >= 0 && mid + 1 <= n - 1 &&
                    nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                    return nums[mid];
                } else {
                    low = mid + 1;
                }
            }
        }
        return ans;
    }
};