class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int last = nums.size() - 1;
        int ans = nums[0];
        while (low <= high) {
            while (low < high && nums[low] == nums[low + 1]) {
                low++;
            }
            while (high > low && nums[high] == nums[high-1]) {
                high--;
            }

            int mid = low + (high - low) / 2;
            ans = min(ans, nums[mid]);
            if (nums[mid] >= nums[last]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};