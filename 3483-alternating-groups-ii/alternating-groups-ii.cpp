class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int cnt = 0;
        int i = 0, j = 1;
        int n = nums.size();
        while (j < n + k - 1) {
            if (nums[(j - 1 + n) % n] != nums[j % n]) {
                if (j - i + 1 == k) {
                    i++;
                    cnt++;
                }
            } else {
                i = j;
            }

            j++;
        }
        return cnt;
    }
};