class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low = 0, high = nums.size() - 1;
        int last = nums[high];
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
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
        return min(nums[0],nums[n-1]);
    }
};