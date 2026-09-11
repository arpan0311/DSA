class Solution {
public:
    bool solve(int mid, vector<int>& nums) {
        int maxi = max(nums[mid - 1], nums[mid + 1]);
        return nums[mid] > maxi;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n >= 2) {
            if (nums[0] > nums[1]) {
                return 0;
            }
            if (nums[n - 2] < nums[n - 1]) {
                return n - 1;
            }
        } else {
            return 0;
        }

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(mid, nums)) {
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};