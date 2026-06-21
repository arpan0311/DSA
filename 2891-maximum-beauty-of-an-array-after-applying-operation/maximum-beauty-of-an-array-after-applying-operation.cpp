class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int i = 0;
        int j = 0;

        int maxBeauty = 0;

        while (i < n) {
            while (j < n && nums[j] <= nums[i] + 2 * k) { // y <= x + 2*k
                j++;
            }

            maxBeauty = max(maxBeauty, j - i);
            i++;
        }

        return maxBeauty;
    }
};