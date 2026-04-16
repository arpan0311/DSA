class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // zero ki swaping hogi nonzero element ke sath
        int i = 0;
        int n = nums.size();
        while (i < nums.size()) {
            if (nums[i] == 0) {
                int j = i + 1;
                while (j < n && nums[j] == 0) {
                    j++;
                }
                if (j < n) {
                    swap(nums[i], nums[j]);
                }
            }
            i++;
        }
    }
};