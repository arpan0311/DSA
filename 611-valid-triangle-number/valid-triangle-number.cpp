class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        while (k >= 2) {
            int i = 0;
            while (i < k) {
                int j = i + 1;

                while (j < k && nums[i] + nums[j] <= nums[k]) {
                    j++;
                }

                if (i != j && j != k && nums[i] + nums[j] > nums[k]) {
                    cnt += (k - j);
                }
                i++;
            }
            k--;
        }
        return cnt;
    }
};